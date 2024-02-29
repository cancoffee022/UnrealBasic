// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameWidget/GameWidget.h"
#include "Widget/PlayerStateWidget/PlayerStateWidget.h"

#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Overlay_Player = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Player")));
	Overlay_Additive = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Additive")));

	PlayerStateWidget = Cast<UPlayerStateWidget>(GetWidgetFromName(TEXT("PlayerStateWidget")));
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
