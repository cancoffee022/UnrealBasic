// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"

void UPlayerCharacterAnimInstance::SetCurrentSpeed(float currentSpeed)
{
	CurrentSpeed = currentSpeed;
}

void UPlayerCharacterAnimInstance::SetGoundedState(bool isGrounded)
{
	bIsGrounded = isGrounded;
}
