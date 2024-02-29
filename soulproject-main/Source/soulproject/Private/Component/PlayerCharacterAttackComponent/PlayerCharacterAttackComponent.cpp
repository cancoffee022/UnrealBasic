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

	_IsAttacking = false;

	IsAttackAreaEnabled = false;
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
	// 진행중인 공격이 있는가?
	if (CurrentAttackData != nullptr) return;

	// 요청된 공격이 있는가?
	if (RequestAttackQueue.IsEmpty()) return;

	// 요청된 공격을 얻습니다
	FAttackData* requestedAttack;
	RequestAttackQueue.Dequeue(requestedAttack);

	AttackDectectedEnemies.Empty();

	
	// 현재 공격을 요청된 공격으로 설정합니다.
	CurrentAttackData = requestedAttack;
	ApplyDamage = CurrentAttackData->AttackDamage;
	_IsAttacking = true;

	if (CurrentAttackData->LookForward)
	{
		FRotator controlRotation = PlayerCharacter->GetControlRotation();
		controlRotation.Pitch = controlRotation.Roll = 0;

		PlayerCharacter->SetActorRotation(controlRotation);
	}

	// 연계공격임을 나타냅니다
	bool isLinkAttack = false;

	if(PrevAttackData != nullptr)
		isLinkAttack = (PrevAttackData->AttackName == CurrentAttackData->AttackName);

	// 연계공격이 아닌 경우 이전 공격을 초기화합니다.
	if (!isLinkAttack) PrevAttackData = nullptr;

	CurrentCombo = FMath::Clamp(CurrentCombo + 1, 0, TargetCombo);

	// 같은 공격을 진행하는 경우
	if (isLinkAttack)
	{
		int32 sectionNameIndex = CurrentCombo - 1;
		FName sectionName = CurrentAttackData->LinkableAttackSectionNames[sectionNameIndex];
		PlayerCharacter->PlayAnimMontage(CurrentAttackData->UseAnimMontage, 1.0f, sectionName);
	}
	else
	{
		// 공격을 시작합니다.
		PlayerCharacter->PlayAnimMontage(CurrentAttackData->UseAnimMontage);
	}

}

void UPlayerCharacterAttackComponent::CheckAttackArea()
{
	// 공격중이 아닌 경우 함수 종료
	if (!IsAttackAreaEnabled) return;
	
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
			if (!AttackDectectedEnemies.Contains(enemyCharacter))
			{
				AttackDectectedEnemies.Add(enemyCharacter);
				//UE_LOG(LogTemp, Warning, TEXT("Apply Damage 99"));

				// 적에게 가할 피해량 계산
				float damage = (Atk * 0.5f) + ApplyDamage;

				UGameplayStatics::ApplyDamage(
					enemyCharacter,
					damage,
					PlayerCharacter->GetController(),
					PlayerCharacter,
					UDamageType::StaticClass());
			}
		}
	}
}


void UPlayerCharacterAttackComponent::UpdateAtk(float atk)
{
	Atk = atk;
}

void UPlayerCharacterAttackComponent::UpdateWeaponSocketLocation(UStaticMeshComponent* weaponMesh)
{
	_CurrentSaberStartSocketLocation = weaponMesh->GetSocketTransform(WEAPON_SOCKET_START).GetLocation();
	_CurrentSaberEndSocketLocation = weaponMesh->GetSocketTransform(WEAPON_SOCKET_END).GetLocation();
}

void UPlayerCharacterAttackComponent::ClearCurrentAttack()
{
	// 연계공격이 끝난 경우
	if (CurrentCombo == TargetCombo)
	{
		CurrentCombo = TargetCombo = 0;
		PrevAttackData = nullptr;
		ApplyDamage = 0.f;
		_IsAttacking = false;
		StartCheckingNextAttackInput();
	}
	//else
	//{
	//	PrevAttackData = CurrentAttackData;
	//	CurrentAttackData = nullptr;
	//}
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
		// 목표 콤보를 증가시킵니다
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
		// 재생중이던 애니메이션 몽타주를 정지합니다
		//PlayerCharacter->StopAnimMontage();

		PrevAttackData = CurrentAttackData;
		CurrentAttackData = nullptr;
	}

}

void UPlayerCharacterAttackComponent::EnableAttackArea()
{
	IsAttackAreaEnabled = true;
}

void UPlayerCharacterAttackComponent::DisableAttackArea()
{
	IsAttackAreaEnabled = false;
}

