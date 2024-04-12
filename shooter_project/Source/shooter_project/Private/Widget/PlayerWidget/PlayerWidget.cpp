// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/PlayerWidget/PlayerWidget.h"

#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"

void UPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// ��ȣ �ۿ� �г��� ����ϴ�
	HideInteractionWidget();
}

void UPlayerWidget::ShowInteractionItem(FText itemName)
{
	// ��ȣ �ۿ� �г��� ǥ���մϴ�
	HorizontalBox_InteractionItem->SetVisibility(ESlateVisibility::Visible);

	// ǥ���� ������ �̸��� �����մϴ�
	TextBlock_ItemName->SetText(itemName);

}

void UPlayerWidget::HideInteractionWidget()
{
	// ��ȣ �ۿ� �г��� ����ϴ�
	HorizontalBox_InteractionItem->SetVisibility(ESlateVisibility::Collapsed);
}

void UPlayerWidget::UpdateBulletRemainText(int remain, int max)
{
	FString text = FString::Printf(TEXT("%d / %d"), remain, max);

	TextBlock_BulletRemain->SetText(FText::FromString(text));
}
