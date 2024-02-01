// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/EnemyWidget/EnemyWidget.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UEnemyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// ���� �������Ʈ���� ���� �̸��� �̿��Ͽ� ����  ��ü�� ã���ϴ�.
	Text_Name = Cast<UTextBlock>(GetWidgetFromName("Text_Name"));
	Progressbar_Hp = Cast<UProgressBar>(GetWidgetFromName("Progressbar_Hp"));
}

void UEnemyWidget::InitializeEnemyWidget(FText name, float maxHp)
{
	// �ִ� ü�� ����
	MaxHp = maxHp;

	// �̸� �ؽ�Ʈ ����
	Text_Name->SetText(name);

	SetHp(MaxHp);

	HideWidget();
}

void UEnemyWidget::SetHp(float newHp)
{
	float hpValue = newHp / MaxHp;
	Progressbar_Hp->SetPercent(hpValue);
}

void UEnemyWidget::ShowWidget()
{
	Text_Name->SetVisibility(ESlateVisibility::Visible);
	Progressbar_Hp->SetVisibility(ESlateVisibility::Visible);
}

void UEnemyWidget::HideWidget()
{
	Text_Name->SetVisibility(ESlateVisibility::Hidden);
	Progressbar_Hp->SetVisibility(ESlateVisibility::Hidden);
}
