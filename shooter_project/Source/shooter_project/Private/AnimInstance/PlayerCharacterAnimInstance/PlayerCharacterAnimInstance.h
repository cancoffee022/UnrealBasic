// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsMove;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool  IsInAir;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float  ZVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector Direction;


public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
