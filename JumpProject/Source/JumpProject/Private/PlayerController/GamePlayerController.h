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
	// ���� ī�޶� ������Ʈ�� ��Ÿ���ϴ�
	UPROPERTY()
	class UCameraComponent* CameraComponent;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent();

private:
	// ī�޶� ������Ʈ�� ã���ϴ�
	void FindCameraComponent();

	// ���� Ű�� ������ �� ȣ��Ǵ� ��� �Լ�
	void OnJumpKeyPressed();
};
