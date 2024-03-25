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

	if (IsFly)
	{
		FlyMovement(DeltaTime);
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

void UDragonCharacterMovementComponent::FlyMovement(float dt)
{
	USkeletalMeshComponent* bodyMesh = DragonCharacter->GetMesh();

	FVector currentLocation = bodyMesh->GetRelativeLocation();
	FVector targetLocation = FVector::UpVector * FlyTargetHeight;

	FVector nextLocation;
	
	if (IsFalling)
	{
		nextLocation = currentLocation + (FVector::DownVector * 3000.0f * dt);
		if (nextLocation.Z < targetLocation.Z)
		{
			IsFalling = false;
			nextLocation.Z = targetLocation.Z;
		}
		bodyMesh->SetRelativeLocation(nextLocation);
	}
	else
	{
		bodyMesh->SetRelativeLocation(
			FMath::VInterpTo(bodyMesh->GetRelativeLocation(),
				targetLocation, dt, 1.5f));
	}


	if (FVector::Distance(currentLocation, targetLocation) < 1.0f)
	{
		bodyMesh->SetRelativeLocation(targetLocation);
		IsFly = false;
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

void UDragonCharacterMovementComponent::StartFlyUp(float targetHeight)
{
	if (!IsFly)
	{
		IsFly = true;
		FlyTargetHeight = targetHeight;

		USkeletalMeshComponent* bodyMesh = DragonCharacter->GetMesh();
		BodyMeshLocation = bodyMesh->GetRelativeLocation();
	}

}

void UDragonCharacterMovementComponent::StartFalling()
{
	if (!IsFly)
	{
		IsFly = true;
		IsFalling = true;
		FlyTargetHeight = BodyMeshLocation.Z;
	}
}

void UDragonCharacterMovementComponent::FinishFlying()
{
	IsFalling = false;
	IsFly = false;
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

