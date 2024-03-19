// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/DragonCharacter/DragonCharacterAnimInstance.h"

void UDragonCharacterAnimInstance::AnimNotify_TurnLeft()
{
	OnTurn.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_TurnRight()
{
	OnTurn.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_DashFinished()
{
	OnDashFinished.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_OnBreathFireStarted()
{
	OnBreathFireStarted.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_OnBreathFireFinished()
{
	OnBreathFireFinished.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_OnClawAttackStarted()
{
	OnClawAttackStarted.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_OnClawAttackFinished()
{
	OnClawAttackFinished.Broadcast();
}
