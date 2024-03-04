// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/EnemyStateWidget/EnemyStateWidget.h"

#include "Actor/EnemyCharacter/EnemyCharacter.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "Structure/EnemyData/EnemyData.h"

void UEnemyStateWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TextBlock_EnemyName = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_EnemyName")));
	Progressbar_Hp = Cast<UProgressBar>(GetWidgetFromName(TEXT("Progressbar_Hp")));
}

void UEnemyStateWidget::NativeTick(const FGeometry& myGeometry, float dt)
{
	Super::NativeTick(myGeometry, dt);

	// �� ��ȿ��
	bool targetEnemyIsValid = IsValid(TargetEnemy);

	// �� �����
	bool enemyIsDead = false;
	if (targetEnemyIsValid) enemyIsDead = TargetEnemy->IsDeadState();

	// ��ǥ �� ĳ���Ͱ� ��ȿ�ϸ鼭 ������� �ʾ��� ���
	if (targetEnemyIsValid && !enemyIsDead)
	{
		// �� ������ ����ϴ�
		const FEnemyData* enemyData = TargetEnemy->GetEnemyData();

		// ���� ü���� ����ϴ�
		float currentHp = TargetEnemy->GetCurrentHp();

		// ���� �̸��� ����ϴ�
		TextBlock_EnemyName->SetText(enemyData->Name);

		Progressbar_Hp->SetPercent(currentHp / enemyData->MaxHP);
	}
	else
	{
		// ��ǥ �� nullptr
		TargetEnemy = nullptr;

		// ������ ����ϴ�
		SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UEnemyStateWidget::UpdateTargetEnemy(AEnemyCharacter* newTargetEnemy)
{
	TargetEnemy = newTargetEnemy;
}
