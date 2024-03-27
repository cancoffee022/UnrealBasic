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

public:
	virtual void SetupInputComponent() override;

	virtual void OnPossess(class APawn* pawn) override;

private:
	void OnGetItemPressed();
	void OnGetItemReleased();

	void OnFirePressed();
	void OnFireReleased();
	
	void OnZoomReleased();
	void OnZoomReleased();

	void OnVerticalInput(float axis);
	void OnHorizontalInput(float axis);

	void OnMouseX(float axis);
	void OnMouseX(float axis)
	
};
