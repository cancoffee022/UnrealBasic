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
	
	// 상대 위젯을 나타냅니다
	UPROPERTY()
	class UPlayerStateWidget* PlayerStateWidget;

	// 적 상태 위젯을 나타냅니다
	UPROPERTY()
	class UEnemyStateWidget* EnemyStateWidget;
	
	// 적 상태 위젯이 띄워진 시간을 저장할 변수
	UPROPERTY()
	float EnemyStateWidgetFloatingTime;

protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& myGeometry, float dt) override;

public:
	// Overlay_Additive에 위젯을 추가합니다
	void FloatingWidgetAdditive(class UUserWidget* widgetInstance);

	// Overlay_Additive에 추가된 위젯을 삭제합니다
	void RemoveWidgetAdditive(class UUserWidget* widgetForClose);

	// 상태 위젯을 반환합니다.
	class UPlayerStateWidget* GetPlayerStateWidget() const;

	void ShowEnemyState(class AEnemyCharacter* enemyCharacter);
	void HideEnemyState();

};
