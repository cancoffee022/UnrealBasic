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

	// �� ���� ������ ����ϴ�
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

UPlayerStateWidget* UGameWidget::GetPlayerStateWidget() const
{
	return PlayerStateWidget;
}

void UGameWidget::ShowEnemyState(AEnemyCharacter* enemyCharacter)
{
	// ������ ǥ��
	EnemyStateWidget->SetVisibility(ESlateVisibility::Visible);
	EnemyStateWidget->UpdateTargetEnemy(enemyCharacter);

	// ������ ����� �ð��� ����
	EnemyStateWidgetFloatingTime = GetWorld()->GetTimeSeconds();
}

void UGameWidget::HideEnemyState()
{
	// ������ �����
	EnemyStateWidget->SetVisibility(ESlateVisibility::Hidden);
}
