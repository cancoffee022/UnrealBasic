// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMapWidget.generated.h"


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

protected:
	virtual void NativeConstruct() override;

private:
	// 사용되는 모든 위젯을 찾습니다
	void FindAllWidgets();

public:
	// AI 심볼을 XY위치에 설정합니다.
	void SetAISimbol(int x, int y);
};
