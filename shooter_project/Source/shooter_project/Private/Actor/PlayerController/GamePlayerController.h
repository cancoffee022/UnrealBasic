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

private:
	// È­¸é¿¡ ¶ç¿ï À§Á¬ Å¬·¡½º
	UPROPERTY()
	TSubclassOf<class UPlayerWidget> WidgetBP_PlayerWidget;

	// È­¸é¿¡ ¶ç¿öÁø ÇÃ·¹ÀÌ¾î À§Á¬ °´Ã¼
	UPROPERTY()
	class UPlayerWidget* PlayerWidget;

public:
	AGamePlayerController();

protected:
	virtual void SetupInputComponent() override;

	virtual void OnPossess(class APawn* pawn) override;

private:
	void OnGetItemPressed();
	void OnGetItemReleased();

	void OnFirePressed();
	void OnFireReleased();
	
	void OnZoomPressed();
	void OnZoomReleased();

	void OnJumpInput();

	void OnVerticalInput(float axis);
	void OnHorizontalInput(float axis);

	void OnMouseX(float axis);
	void OnMouseY(float axis);

public:
	FORCEINLINE class UPlayerWidget* GetPlayerWidget() const
	{
		return PlayerWidget;
	}
};
