// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"

#include "../../Component/PlayerCharacterAnimController/PlayerCharacterAnimController.h"

void UPlayerCharacterAnimInstance::SetAnimController(UPlayerCharacterAnimController* animController)
{
	AnimController = animController;
}

void UPlayerCharacterAnimInstance::SetCurrentSpeed(float currentSpeed)
{
	CurrentSpeed = currentSpeed;
}

void UPlayerCharacterAnimInstance::SetGoundedState(bool isGrounded)
{
	bIsGrounded = isGrounded;
}

void UPlayerCharacterAnimInstance::AnimNotify_AttackEnd()
{
	AnimController->OnAttackEnded();
}

void UPlayerCharacterAnimInstance::AnimNotify_StartNextAttackCheck()
{
	AnimController->OnNextAttackCheckStarted();
}

void UPlayerCharacterAnimInstance::AnimNotify_FinishNextAttackCheck()
{
	AnimController->OnNextAttackCheckFinished();
}

