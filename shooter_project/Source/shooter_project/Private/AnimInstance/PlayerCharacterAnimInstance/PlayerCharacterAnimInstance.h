// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Enum/WorldItemType.h"
#include "PlayerCharacterAnimInstance.generated.h"

DECLARE_EVENT(UPlayerCharacterAnimInstance, FOnReloadedEventSignature)

/**
 * 
 */
UCLASS()
class UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	FOnReloadedEventSignature OnReloadedEvent;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsMove;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float PitchAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool  IsInAir;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float  ZVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector Direction;

	// ��� ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsEquipped;

	// ������ ������ Ÿ��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EWorldItemType EquippedItemType;

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UFUNCTION()
	void AnimNotify_OnReloaded();
};
