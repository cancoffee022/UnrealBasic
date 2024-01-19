#include "Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "../../Structure/AttackData/AttackData.h"

#include "Animation/AnimMontage.h"

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

	SkillProcedure();
}

void UPlayerCharacterAttackComponent::SkillProcedure()
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

//FAttackData* UPlayerCharacterAttackComponent::GetAttackData(FName attackName)
//{
//	//FAttackData** result = 
//	return *AttackDatas.Find(attackName);
//}

void UPlayerCharacterAttackComponent::ClearCurrentAttack()
{
	// ��������� ���� ���
	if (CurrentCombo == TargetCombo)
	{
		CurrentCombo = TargetCombo = 0;
		PrevAttackData = nullptr;
		StartCheckingNextAttackInput();
	}
	else
	{
		PrevAttackData = CurrentAttackData;
		CurrentAttackData = nullptr;
	}

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

