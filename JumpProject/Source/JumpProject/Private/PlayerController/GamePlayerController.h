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
	// 사용될 카메라 컴포넌트를 나타냅니다
	UPROPERTY()
	class UCameraComponent* CameraComponent;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent();

private:
	// 카메라 컴포넌트를 찾습니다
	void FindCameraComponent();

	// 점프 키가 눌렸을 때 호출되는 멤버 함수
	void OnJumpKeyPressed();
};
