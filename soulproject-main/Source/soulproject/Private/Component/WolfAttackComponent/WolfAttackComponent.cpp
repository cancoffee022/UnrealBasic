
#include "Component/WolfAttackComponent/WolfAttackComponent.h"

#include "Actor/EnemyCharacter/Wolf/WolfCharacter.h"

// Sets default values for this component's properties
UWolfAttackComponent::UWolfAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_ATTACK(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/AnimalVarietyPack/Wolf/Animations/AnimMontage_Attack.AnimMontage_Attack'"));
	
	if (ANIMMONTAGE_ATTACK.Succeeded())
	{
		AttackAnimMontage = ANIMMONTAGE_ATTACK.Object;
	}
}


// Called when the game starts
void UWolfAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWolfAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWolfAttackComponent::Attack()
{
	Cast<AWolfCharacter>(GetOwner())->PlayAnimMontage(AttackAnimMontage);
}

