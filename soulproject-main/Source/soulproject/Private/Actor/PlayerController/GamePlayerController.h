// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

#define PLAYERCHARACTER_DATA_NORMAL			TEXT("Normal")

/**
 * 
 */
UCLASS()
class AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// 플레이어 데이터 테이블 에셋
	UPROPERTY()
	class UDataTable* PlayerCharacterDataTable;

	// 게임 위젯 블루프린트 클래스
	UPROPERTY()
	TSubclassOf<class UGameWidget> GameWidgetClass;

	// 게임 위젯
	UPROPERTY()
	class UGameWidget* GameWidget;

	// 플레이어 캐릭터 데이터
	struct FPlayerCharacterData* PlayerCharacterData;

	// 현재 Hp
	float CurrentHp;

	// 현재 Stamina
	float CurrentStamina;

public :
	AGamePlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected :
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* pawn) override;

private :
	// 수직 축 입력 시 호출됩니다.
	void OnVerticalMovementInput(float axis);

	// 수평 축 입력 시 호출됩니다.
	void OnHorizontalMovementInput(float axis);

	// 마우스 수평 축 입력 시 호출됩니다.
	void OnMouseXInput(float axis);

	// 마우스 수직 축 입력 시 호출됩니다.
	void OnMouseYInput(float axis);

	// 마우스 휠 입력시 호출합니다.
	void OnZoomInput(float axis);

	// 점프 입력시 호출됩니다.
	void OnJumpInput();

	// 공격 입력 시 호출됩니다.
	void OnAttackInput();

	// 상호작용 키 입력시 호출됩니다
	void OnInteractionInput();

public:
	class UGameWidget* GetGameWidget() const;

	void SetCameraViewTarget(class AActor* target);
	void ClearCameraViewTarget();

	// 상태 위젯을 초기화합니다
	void InitializePlayerStateWidget(float maxHp, float maxStamina);

	// 조종하는 캐릭터가 피해를 입을 경우 호출됩니다
	// damage : 입은 피해량이 전달됩니다
	void OnDamaged(float damage);
	
};
