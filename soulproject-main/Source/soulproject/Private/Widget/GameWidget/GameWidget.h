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
	// Overlay_Additive�� ������ �߰��մϴ�
	void FloatingWidgetAdditive(class UUserWidget* widgetInstance);

	// Overlay_Additive�� �߰��� ������ �����մϴ�
	void RemoveWidgetAdditive(class UUserWidget* widgetForClose);

};
