// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/EnemyWidget/EnemyWidget.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UEnemyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 위젯 블루프린트에서 위젯 이름을 이용하여 위젯  객체를 찾습니다.
	Text_Name = Cast<UTextBlock>(GetWidgetFromName("Text_Name"));
	Progressbar_Hp = Cast<UProgressBar>(GetWidgetFromName("Progressbar_Hp"));
}

void UEnemyWidget::InitializeEnemyWidget(FText name, float maxHp)
{
	// 최대 체력 설정
	MaxHp = maxHp;

	// 이름 텍스트 설정
	Text_Name->SetText(name);

	SetHp(MaxHp);
}

void UEnemyWidget::SetHp(float newHp)
{
	float hpValue = newHp / MaxHp;
	Progressbar_Hp->SetPercent(hpValue);
}
