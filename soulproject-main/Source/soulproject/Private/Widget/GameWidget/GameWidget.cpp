// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameWidget/GameWidget.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Overlay_Player = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Player")));
	Overlay_Additive = Cast<UOverlay>(GetWidgetFromName(TEXT("Overlay_Additive")));
}

void UGameWidget::FloatingWidgetAdditive(UUserWidget* widgetInstance)
{
	// Overrlay_Additive ������ �߰��մϴ�.
	Overlay_Additive->AddChild(widgetInstance);

	// ������ ������ ���� ������ ����ϴ�
	UOverlaySlot* widgetSlot = Cast<UOverlaySlot>(widgetInstance->Slot);

	// ���� ȭ�� ä���
	widgetSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
	widgetSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
}

void UGameWidget::RemoveWidgetAdditive(UUserWidget* widgetForClose)
{
	//widgetForClose->RemoveFromParent();
	Overlay_Additive->RemoveChild(widgetForClose);
}