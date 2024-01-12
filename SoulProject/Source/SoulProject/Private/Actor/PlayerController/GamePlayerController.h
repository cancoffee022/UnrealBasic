// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	// 수직 축 입력시 호출
	void OnVerticalMovementInput(float axis);

	// 수평 축 입력시 호출
	void OnHorizontalMovementInput(float axis);

	// 마우스 수평 축 입력시 호출됩니다
	void OnMouseXInput(float axis);
	// 마우스 수직 축 입력시 호출됩니다
	void OnMouseYInput(float axis);
	
};
