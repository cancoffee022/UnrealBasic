// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/NpcDialogWidget/NpcDialogWidget.h"
#include "Structure/NpcData/NpcData.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"

void UNpcDialogWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Text_Name = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Name")));
	Text_Dialog = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Dialog")));
	Button_Close = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));

	Button_Close->OnClicked.AddDynamic(this, &ThisClass::OnCloseButtonClicked);

	// ���� �ִϸ��̼� ���
	PlayAnimation(FadeInAnimation);
}

void UNpcDialogWidget::InitializeNpcDialogWidget(FNpcData* npcData, FOnDialogCloseEventSignature onDialogClosed)
{
	Text_Name->SetText(npcData->Name);
	Text_Dialog->SetText(npcData->DialogText);

	OnDialogClosed = onDialogClosed;
}

void UNpcDialogWidget::OnCloseButtonClicked()
{
	OnDialogClosed.Broadcast();
}
