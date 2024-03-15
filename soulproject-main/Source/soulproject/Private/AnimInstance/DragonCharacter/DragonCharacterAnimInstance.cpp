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
