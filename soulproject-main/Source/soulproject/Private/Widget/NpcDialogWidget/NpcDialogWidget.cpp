// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/NpcDialogWidget/NpcDialogWidget.h"
#include "Structure/NpcData/NpcData.h"
#include "Components/TextBlock.h"

void UNpcDialogWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Text_Name = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Name")));
	Text_Dialog = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Dialog")));

}

void UNpcDialogWidget::InitializeNpcDialogWidget(FNpcData* npcData)
{
	Text_Name->SetText(npcData->Name);
	Text_Dialog->SetText(npcData->DialogText);
}
