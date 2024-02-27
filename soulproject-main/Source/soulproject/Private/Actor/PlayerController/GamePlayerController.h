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
	// ���� ���� �������Ʈ Ŭ����
	UPROPERTY()
	TSubclassOf<class UGameWidget> GameWidgetClass;

	// ���� ����
	UPROPERTY()
	class UGameWidget* GameWidget;

public :
	AGamePlayerController();

protected :
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* pawn) override;

private :
	// ���� �� �Է� �� ȣ��˴ϴ�.
	void OnVerticalMovementInput(float axis);

	// ���� �� �Է� �� ȣ��˴ϴ�.
	void OnHorizontalMovementInput(float axis);

	// ���콺 ���� �� �Է� �� ȣ��˴ϴ�.
	void OnMouseXInput(float axis);

	// ���콺 ���� �� �Է� �� ȣ��˴ϴ�.
	void OnMouseYInput(float axis);

	// ���콺 �� �Է½� ȣ���մϴ�.
	void OnZoomInput(float axis);

	// ���� �Է½� ȣ��˴ϴ�.
	void OnJumpInput();

	// ���� �Է� �� ȣ��˴ϴ�.
	void OnAttackInput();

	// ��ȣ�ۿ� Ű �Է½� ȣ��˴ϴ�
	void OnInteractionInput();

public:
	class UGameWidget* GetGameWidget() const;

	void SetCameraViewTarget(class AActor* target);
	void ClearCameraViewTarget();
	
};
