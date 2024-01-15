// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "ZoomableSpringArmComponent.generated.h"

/**
 * 
 */
UCLASS()
class UZoomableSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

private:
	// 카메라 줌에 곱해질 승수입니다.
	float ZoomMultiplier;
	
	// 카메라 줌 범위
	float ZoomLengthMin;
	float ZoomLengthMax;

public:
	UZoomableSpringArmComponent();
		
	void ZoomCamera(float axis);
};
