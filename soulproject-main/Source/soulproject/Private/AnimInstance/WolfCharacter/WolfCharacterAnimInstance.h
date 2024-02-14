// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WolfCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UWolfCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

public:
	void SetCurrentSpeed(float newSpeed);
	
};