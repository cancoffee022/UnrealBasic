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
	// 캐릭터에 적용된 현재 속력을 나타냅니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

public:
	void SetCurrentSpeed(float currentSpeed);
};
