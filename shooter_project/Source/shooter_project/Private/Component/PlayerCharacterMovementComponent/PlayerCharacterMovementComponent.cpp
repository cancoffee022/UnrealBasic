// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "GameFramework/Character.h"

UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	bUseControllerDesiredRotation = true;
}

void UPlayerCharacterMovementComponent::OnVerticalMovement(float axis)
{
	// 컨트롤러 Yaw 회전을 얻습니다
	double yawRotation = GetCharacterOwner()->GetControlRotation().Yaw;
	FRotator rotationOnlyZAxis = FRotator(0.f, yawRotation, 0.f);

	FVector forwardVector = FRotationMatrix(rotationOnlyZAxis).GetUnitAxis(EAxis::X);

	AddInputVector(forwardVector * axis);
}

void UPlayerCharacterMovementComponent::OnHorizontalMovement(float axis)
{
	double yawRotation = GetCharacterOwner()->GetControlRotation().Yaw;
	FRotator rotationOnlyZAxis = FRotator(0.f, yawRotation, 0.f);

	FVector rightVector = FRotationMatrix(rotationOnlyZAxis).GetUnitAxis(EAxis::Y);

	AddInputVector(rightVector * axis);
}
