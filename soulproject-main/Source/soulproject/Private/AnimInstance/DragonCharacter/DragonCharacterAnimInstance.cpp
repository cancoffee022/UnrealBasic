// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/DragonCharacter/DragonCharacterAnimInstance.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

void UDragonCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(GetOwningActor());

	// 유효성 검사
	if (!IsValid(dragonCharacter)) return;

	// 속도 갱신
	FVector velocity = dragonCharacter->GetVelocity();
	velocity.Z = 0;
	XYSpeed = velocity.Length();

}

void UDragonCharacterAnimInstance::StartFly()
{
	IsFly = true;
}

void UDragonCharacterAnimInstance::UpdateFlyDirection(FIntVector direction)
{
	FlyDirection = direction;
}

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

void UDragonCharacterAnimInstance::AnimNotify_OnRushAttackStarted()
{
	OnRushAttackStarted.Broadcast();
}

void UDragonCharacterAnimInstance::AnimNotify_OnRushAttackFinished()
{
	OnRushAttackFinished.Broadcast();
}
