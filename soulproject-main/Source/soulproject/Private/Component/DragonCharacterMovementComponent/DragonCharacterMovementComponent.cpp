#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

UDragonCharacterMovementComponent::UDragonCharacterMovementComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}

void UDragonCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	DragonCharacter = Cast<ADragonCharacter>(GetOwner());
}

void UDragonCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsDash)
	{
		CheckDashFinish();
	}
}

void UDragonCharacterMovementComponent::CheckDashFinish()
{
	float speed = DragonCharacter->GetVelocity().Size();
	if (speed < 0.1)
	{
		IsDash = false;
	}
}

void UDragonCharacterMovementComponent::StartDash(FVector direction, float power)
{
	IsDash = true;
	DragonCharacter->LaunchCharacter(direction, power);
	DragonCharacter->PlayMoveAnimMontage(ANIMMONTAGE_SECTION_DASHBACKWARD);
}

