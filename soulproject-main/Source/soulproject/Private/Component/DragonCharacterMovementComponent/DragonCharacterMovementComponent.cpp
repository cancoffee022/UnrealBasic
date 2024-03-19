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

	if (IsYawTurnning)
	{
		TurnningSmooth(DeltaTime);
	}
}

void UDragonCharacterMovementComponent::TurnningSmooth(float dt)
{
	// 현재 회전
	FRotator currentRotation = DragonCharacter->GetActorRotation();

	// 목표 회전
	FRotator targetRotation = FRotator(0, TargetYawAngle, 0);
	
	if (IsYawTurnFinished())
	{
		TargetYawAngle = targetRotation.Yaw;
		DragonCharacter->SetActorRotation(targetRotation);

		IsYawTurnning = false;
	}
	else
	{
		// 부드럽게 회전
		FRotator newRotation = FMath::RInterpTo(
			currentRotation,
			targetRotation,
			dt, 15.0f);

		DragonCharacter->SetActorRotation(newRotation);

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

void UDragonCharacterMovementComponent::SetTargetYawAngle(float targetYawAngle)
{
	TargetYawAngle = targetYawAngle;
}

void UDragonCharacterMovementComponent::StartTurn()
{
	IsYawTurnning = true;
}



void UDragonCharacterMovementComponent::StartDash(FVector direction, float power)
{
	IsDash = true;
	DragonCharacter->LaunchCharacter(direction, power);
	DragonCharacter->PlayMoveAnimMontage(ANIMMONTAGE_SECTION_DASHBACKWARD);
}

bool UDragonCharacterMovementComponent::IsYawTurnFinished()
{
	// 현재 회전
	FRotator currentRotation = DragonCharacter->GetActorRotation();

	// 목표 회전
	FRotator targetRotation = FRotator(0, TargetYawAngle, 0);

	return (currentRotation.Equals(targetRotation, 5.f));
}

