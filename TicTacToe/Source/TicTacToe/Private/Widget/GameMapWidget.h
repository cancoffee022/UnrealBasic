// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMapWidget.generated.h"

// 플레이어 심볼이 갱신될 경우를 나타내기 위한 대리자 형식
// int32 x: 심볼이 설정된 X 위치
// int32 y: 심볼이 설정된 Y 위치
DECLARE_DELEGATE_TwoParams(OnPlayerSimbolUpdated_Signature, int32 /* x */, int32 /* y */)

/**
 * 
 */
UCLASS()
class UGameMapWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	// 심볼 TextBlock 객체들을 저장해둘 배열
	TArray<class UTextBlock*> SimbolTexts;
	/// TArray<Type> : 언리얼에서 제공하는 컨테이너
	/// TSet : 저장 순서가 유지되며, 중복 저장되지 않습니다
	/// TMap : 키와 값이 함께 저장되며, 키는 중복 저장되지 않습니다

	// 플레이어 심볼이 갱신되었을 경우 발생하는 이벤트입니다.
	OnPlayerSimbolUpdated_Signature OnPlayerSimbolUpdated;

protected:
	virtual void NativeConstruct() override;

private:
	// 사용되는 모든 위젯을 찾습니다
	void FindAllWidgets();

	// 버튼 이벤트를 바인딩 합니다
	void BindButtonEvents();

	UFUNCTION()
	void OnGameBoardClicked(int32 x, int32 y);

	UFUNCTION()
	void OnGameBoardClicked00();
	UFUNCTION()
	void OnGameBoardClicked01();
	UFUNCTION()
	void OnGameBoardClicked02();
	UFUNCTION()
	void OnGameBoardClicked10();
	UFUNCTION()
	void OnGameBoardClicked11();
	UFUNCTION()
	void OnGameBoardClicked12();
	UFUNCTION()
	void OnGameBoardClicked20();
	UFUNCTION()
	void OnGameBoardClicked21();
	UFUNCTION()
	void OnGameBoardClicked22();

public:
	// 플레이어 심볼이 갱신되었을 경우 발생시킬 이벤트를 설정합니다
	FORCEINLINE void SetPlayerSimbolUpdatedEvent(
		OnPlayerSimbolUpdated_Signature onPlayerSimbolUpdated)
	{
		OnPlayerSimbolUpdated = onPlayerSimbolUpdated;
	}

	// AI 심볼을 XY위치에 설정합니다.
	void SetAISimbol(int y, int x);
};
