#include "Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "Animation/AnimMontage.h"

UPlayerCharacterAttackComponent::UPlayerCharacterAttackComponent()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> COMBO_ATTACK_MONTAGE(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/GirlKnight1/Animations/AnimMontage_Attack.AnimMontage_Attack'"));

	if (COMBO_ATTACK_MONTAGE.Succeeded())
	{
		ComboAttackMontage = COMBO_ATTACK_MONTAGE.Object;
	}

	PrimaryComponentTick.bCanEverTick = true;
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
	// ���� �������� ������ �ִ°�?
	if (CurrentAttackName != ATTACK_NONE) return;

	// ��û�� ������ �ִ°�?
	if (RequestAttackQueue.IsEmpty()) return;

	// ��û�� ������ ����ϴ�
	FName requestedAttack;
	RequestAttackQueue.Dequeue(requestedAttack);
	
	// ���� ������ ��û�� �������� �����մϴ�.
	CurrentAttackName = requestedAttack;

	// ������ �����մϴ�.
	StartAttack(CurrentAttackName);

}

void UPlayerCharacterAttackComponent::StartAttack(FName attackInfo)
{
	if (attackInfo == COMBO_ATTACK_01)
	{
		PlayerCharacter->PlayAnimMontage(ComboAttackMontage);
	}
	else if (attackInfo == COMBO_ATTACK_02)
	{
		PlayerCharacter->PlayAnimMontage(ComboAttackMontage);

	}
}

void UPlayerCharacterAttackComponent::ClearCurrentAttack()
{
	CurrentAttackName = ATTACK_NONE;
}

void UPlayerCharacterAttackComponent::RequestAttack(FName attackName)
{
	RequestAttackQueue.Enqueue(attackName);
}

