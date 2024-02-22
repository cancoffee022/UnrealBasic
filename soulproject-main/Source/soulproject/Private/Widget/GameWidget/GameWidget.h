// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS()
class UGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
private: 
	UPROPERTY()
	class UOverlay* Overlay_Player;
	
	UPROPERTY()
	class UOverlay* Overlay_Additive;

protected:
	virtual void NativeConstruct() override;

public:
	// Overlay_Additive에 위젯을 추가합니다
	void FloatingWidgetAdditive(class UUserWidget* widgetInstance);

	// Overlay_Additive에 추가된 위젯을 삭제합니다
	void RemoveWidgetAdditive(class UUserWidget* widgetForClose);

};
