// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/PlayerWidget/PlayerWidget.h"

#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"

void UPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 상호 작용 패널을 숨깁니다
	HideInteractionWidget();
}

void UPlayerWidget::ShowInteractionItem(FText itemName)
{
	// 상호 작용 패널을 표시합니다
	HorizontalBox_InteractionItem->SetVisibility(ESlateVisibility::Visible);

	// 표시할 아이템 이름을 설정합니다
	TextBlock_ItemName->SetText(itemName);

}

void UPlayerWidget::HideInteractionWidget()
{
	// 상호 작용 패널을 숨깁니다
	HorizontalBox_InteractionItem->SetVisibility(ESlateVisibility::Collapsed);
}

void UPlayerWidget::UpdateBulletRemainText(int remain, int max)
{
	FString text = FString::Printf(TEXT("%d / %d"), remain, max);

	TextBlock_BulletRemain->SetText(FText::FromString(text));
}
