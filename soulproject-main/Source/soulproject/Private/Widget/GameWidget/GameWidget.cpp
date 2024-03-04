// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameWidget/GameWidget.h"
#include "Widget/PlayerStateWidget/PlayerStateWidget.h"
#include "Widget/EnemyStateWidget/EnemyStateWidget.h"

#include "Actor/EnemyCharacter/EnemyCharacter.h"

#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Overlay_Player = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Player")));
	Overlay_Additive = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Additive")));

	PlayerStateWidget = Cast<UPlayerStateWidget>(GetWidgetFromName(TEXT("PlayerStateWidget")));
	EnemyStateWidget = Cast<UEnemyStateWidget>(GetWidgetFromName(TEXT("EnemyStateWidget")));

	// 적 상태 위젯을 숨깁니다
	HideEnemyState();
}

void UGameWidget::NativeTick(const FGeometry& myGeometry, float dt)
{
	Super::NativeTick(myGeometry, dt);

	if (GetWorld()->GetTimeSeconds() > EnemyStateWidgetFloatingTime + 5.f)
	{
		HideEnemyState();
	}
}

void UGameWidget::FloatingWidgetAdditive(UUserWidget* widgetInstance)
{
	// Overrlay_Additive 하위로 추가합니다.
	Overlay_Additive->AddChild(widgetInstance);

	// 생성된 위젯에 대한 슬롯을 얻습니다
	UOverlaySlot* widgetSlot = Cast<UOverlaySlot>(widgetInstance->Slot);

	// 위젯 화면 채우기
	widgetSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
	widgetSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
}

void UGameWidget::RemoveWidgetAdditive(UUserWidget* widgetForClose)
{
	//widgetForClose->RemoveFromParent();
	Overlay_Additive->RemoveChild(widgetForClose);
}

UPlayerStateWidget* UGameWidget::GetPlayerStateWidget() const
{
	return PlayerStateWidget;
}

void UGameWidget::ShowEnemyState(AEnemyCharacter* enemyCharacter)
{
	// 위젯을 표시
	EnemyStateWidget->SetVisibility(ESlateVisibility::Visible);
	EnemyStateWidget->UpdateTargetEnemy(enemyCharacter);

	// 위젯이 띄워진 시간을 저장
	EnemyStateWidgetFloatingTime = GetWorld()->GetTimeSeconds();
}

void UGameWidget::HideEnemyState()
{
	// 위젯을 숨기기
	EnemyStateWidget->SetVisibility(ESlateVisibility::Hidden);
}
