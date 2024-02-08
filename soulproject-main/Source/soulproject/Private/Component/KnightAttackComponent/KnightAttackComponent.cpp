#include "Component/KnightAttackComponent/KnightAttackComponent.h"

#include "Actor/EnemyCharacter/Knight/KnightCharacter.h"

// Sets default values for this component's properties
UKnightAttackComponent::UKnightAttackComponent()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> MONTAGE_ATTACK(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/GKnight/Animation/AnimMontage_Attack.AnimMontage_Attack'"));
	if (MONTAGE_ATTACK.Succeeded())
	{
		AttackAnimMontage = MONTAGE_ATTACK.Object;
	}
	
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UKnightAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKnightAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UKnightAttackComponent::Attack()
{
	Cast<AKnightCharacter>(GetOwner())->PlayAnimMontage(AttackAnimMontage);
}

void UKnightAttackComponent::OnAttackFinished()
{
}

