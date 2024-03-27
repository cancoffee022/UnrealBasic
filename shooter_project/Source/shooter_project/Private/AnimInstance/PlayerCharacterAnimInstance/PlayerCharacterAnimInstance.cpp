// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APlayerCharacter* owner = Cast<APlayerCharacter>(GetOwningActor());

	if (!IsValid(owner)) return;

	Speed = owner->GetVelocity().Length();
	IsMove = Speed > 1;
}
