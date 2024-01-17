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
	// 현재 실행중인 공격이 있는가?
	if (CurrentAttackName != ATTACK_NONE) return;

	// 요청된 공격이 있는가?
	if (RequestAttackQueue.IsEmpty()) return;

	// 요청된 공격을 얻습니다
	FName requestedAttack;
	RequestAttackQueue.Dequeue(requestedAttack);
	
	// 현재 공격을 요청된 공격으로 설정합니다.
	CurrentAttackName = requestedAttack;

	// 공격을 시작합니다.
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

