// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/EnemyStateWidget/EnemyStateWidget.h"

#include "Actor/EnemyCharacter/EnemyCharacter.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UEnemyStateWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TextBlock_EnemyName = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_EnemyName")));
	Progressbar_Hp = Cast<UProgressBar>(GetWidgetFromName(TEXT("Progressbar_Hp")));
}

void UEnemyStateWidget::UpdateEnemy(AEnemyCharacter* newTargetEnemy)
{
	TargetEnemy = newTargetEnemy;
}
