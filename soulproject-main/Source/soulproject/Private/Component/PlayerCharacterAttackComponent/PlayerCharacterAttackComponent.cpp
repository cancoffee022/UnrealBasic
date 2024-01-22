#include "Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "../../Actor/EnemyCharacter/EnemyCharacter.h"
#include "../../Structure/AttackData/AttackData.h"

#include "Components/StaticMeshComponent.h"

#include "Animation/AnimMontage.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"


UPlayerCharacterAttackComponent::UPlayerCharacterAttackComponent()
{

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ATTACK_DATA(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_AttackData.DT_AttackData'"));

	if (DT_ATTACK_DATA.Succeeded())
	{
		DT_Attackdata = DT_ATTACK_DATA.Object;
	}

	PrimaryComponentTick.bCanEverTick = true;

	bCheckingNextAttackInput = true;

	_IsCalculatedPrevSaberSocketLocation = false;

	_IsAttacking = false;
}


// Called when the game starts
void UPlayerCharacterAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<AGameCharacter>(GetOwner());

}


// Called every frame
void UPlayerCharacterAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AttackProcedure();
	CheckAttackArea();
}

void UPlayerCharacterAttackComponent::AttackProcedure()
{
	// �������� ������ �ִ°�?
	if (CurrentAttackData != nullptr) return;

	// ��û�� ������ �ִ°�?
	if (RequestAttackQueue.IsEmpty()) return;

	// ��û�� ������ ����ϴ�
	FAttackData* requestedAttack;
	RequestAttackQueue.Dequeue(requestedAttack);

	
	// ���� ������ ��û�� �������� �����մϴ�.
	CurrentAttackData = requestedAttack;
	ApplyDamage = CurrentAttackData->AttackDamage;
	_IsAttacking = true;

	// ����������� ��Ÿ���ϴ�
	bool isLinkAttack = false;

	if(PrevAttackData != nullptr)
		isLinkAttack = (PrevAttackData->AttackName == CurrentAttackData->AttackName);

	// ��������� �ƴ� ��� ���� ������ �ʱ�ȭ�մϴ�.
	if (!isLinkAttack) PrevAttackData = nullptr;

	CurrentCombo = FMath::Clamp(CurrentCombo + 1, 0, TargetCombo);

	// ���� ������ �����ϴ� ���
	if (isLinkAttack)
	{

		int32 sectionNameIndex = CurrentCombo - 1;
		FName sectionName = CurrentAttackData->LinkableAttackSectionNames[sectionNameIndex];
		PlayerCharacter->PlayAnimMontage(CurrentAttackData->UseAnimMontage, 1.0f, sectionName);
	}
	else
	{
		// ������ �����մϴ�.
		PlayerCharacter->PlayAnimMontage(CurrentAttackData->UseAnimMontage);
	}

}

void UPlayerCharacterAttackComponent::CheckAttackArea()
{
	// �������� �ƴ� ��� �Լ� ����
	if (!_IsAttacking) return;

	// ���� ��ġ�� ������ ���� ���
	if (!_IsCalculatedPrevSaberSocketLocation)
	{
		_IsCalculatedPrevSaberSocketLocation = true;

		return;
	}
	
	TArray<AActor*> actorsToIgnore;
	TArray<FHitResult> hitResults;

	bool isHit = UKismetSystemLibrary::SphereTraceMultiByProfile(
		this,
		_CurrentSaberStartSocketLocation,
		_CurrentSaberEndSocketLocation,
		10.0f,
		TEXT("Enemy"),
		false,
		actorsToIgnore,
		EDrawDebugTrace::Type::ForOneFrame,
		hitResults,
		true);

	for (FHitResult& hit : hitResults)
	{
		AEnemyCharacter* enemyCharacter = Cast<AEnemyCharacter>(hit.GetActor());
		if (IsValid(enemyCharacter))
		{
			UE_LOG(LogTemp, Warning, TEXT("Apply DDamage 99"));
			UGameplayStatics::ApplyDamage(
				enemyCharacter,
				ApplyDamage,
				PlayerCharacter->GetController(),
				PlayerCharacter,
				UDamageType::StaticClass());
		}
	}
}

//FAttackData* UPlayerCharacterAttackComponent::GetAttackData(FName attackName)
//{
//	//FAttackData** result = 
//	return *AttackDatas.Find(attackName);
//}

void UPlayerCharacterAttackComponent::UpdateWeaponSocketLocation(UStaticMeshComponent* weaponMesh)
{
	_CurrentSaberStartSocketLocation = weaponMesh->GetSocketTransform(WEAPON_SOCKET_START).GetLocation();
	_CurrentSaberEndSocketLocation = weaponMesh->GetSocketTransform(WEAPON_SOCKET_END).GetLocation();
}

void UPlayerCharacterAttackComponent::ClearCurrentAttack()
{
	// ��������� ���� ���
	if (CurrentCombo == TargetCombo)
	{
		CurrentCombo = TargetCombo = 0;
		PrevAttackData = nullptr;
		ApplyDamage = 0.f;
		_IsAttacking = false;
		_IsCalculatedPrevSaberSocketLocation = false;
		StartCheckingNextAttackInput();
	}
	else
	{
		PrevAttackData = CurrentAttackData;
		CurrentAttackData = nullptr;
	}
	ApplyDamage = 0.f;

	PrevAttackData = CurrentAttackData;
	CurrentAttackData = nullptr;
}

void UPlayerCharacterAttackComponent::RequestAttack(FName attackName)
{
	FString contextString;
	FAttackData* attackData = DT_Attackdata->FindRow<FAttackData>(attackName, contextString);
	
	if (attackData == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttackData is not valid %s"), *attackName.ToString());
		return;
	}

	if (bCheckingNextAttackInput)
	{
		// ��ǥ �޺��� ������ŵ�ϴ�
		if (attackData->GetMaxComboCount() > TargetCombo)
		{
			++TargetCombo;
		}
		else
		{
			return;
		}
		RequestAttackQueue.Enqueue(attackData);
	}

}

void UPlayerCharacterAttackComponent::StartCheckingNextAttackInput()
{
	bCheckingNextAttackInput = true;
}

void UPlayerCharacterAttackComponent::FinishCheckingNextAttackInput()
{
	bCheckingNextAttackInput = false;

	if (CurrentCombo < TargetCombo)
	{
		// ������̴� �ִϸ��̼� ��Ÿ�ָ� �����մϴ�
		//PlayerCharacter->StopAnimMontage();

		PrevAttackData = CurrentAttackData;
		CurrentAttackData = nullptr;
	}

}

