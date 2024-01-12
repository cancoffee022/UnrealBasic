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
	// ���� �� �Է½� ȣ��
	void OnVerticalMovementInput(float axis);

	// ���� �� �Է½� ȣ��
	void OnHorizontalMovementInput(float axis);

	// ���콺 ���� �� �Է½� ȣ��˴ϴ�
	void OnMouseXInput(float axis);
	// ���콺 ���� �� �Է½� ȣ��˴ϴ�
	void OnMouseYInput(float axis);
	
};
