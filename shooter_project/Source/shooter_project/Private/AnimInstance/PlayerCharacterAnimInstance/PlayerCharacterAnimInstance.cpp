// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APlayerCharacter* owner = Cast<APlayerCharacter>(GetOwningActor());

	if (!IsValid(owner)) return;

	Speed = owner->GetCurrentSpeed();
	IsMove = Speed > 1;

	Direction = FVector(owner->GetInputAxisRaw());

	IsInAir = owner->GetMovementComponent()->IsFalling();
	ZVelocity = IsInAir ? owner->GetVelocity().Z : 0.f;
	PitchAngle = owner->GetCameraPitchAngle();

	if (PitchAngle - 180.f > 0) PitchAngle -= 360.f;

	IsEquipped = owner->IsEquipped();
	if (IsEquipped)
	{
		EquippedItemType = owner->GetEquippedItemType();

	}
}
