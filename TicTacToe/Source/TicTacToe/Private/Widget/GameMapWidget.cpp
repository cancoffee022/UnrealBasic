// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMapWidget.h"

// UTextBlock ������� ����
#include "Components/TextBlock.h"

void UGameMapWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Super : �θ�Ŭ������ ��Ÿ���ϴ�
	// ThisClass : �ڽ� Ŭ������ ��Ÿ���ϴ�.
	// this : �ڱ� �ڽ� ��ü�� ��Ÿ���ϴ�.

	// ���Ǵ� ������ ��� ã���ϴ�
	FindAllWidgets();

	// TODO ���� �����ؾ���
	// �׽�Ʈ�� �ڵ�
	SimbolTexts[3]->SetText(FText::FromString(TEXT("Test!")));
}

void UGameMapWidget::FindAllWidgets()
{
	
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_00"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_01"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_02"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_10"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_11"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_12"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_20"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_21"))));
	SimbolTexts.Add(Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_22"))));
	// GetWidgetFromName(NameData) : NameData�� �ش��ϴ� ������ ã�� UWidget* �������� ��ȯ�մϴ�
	// UWidget Ŭ���� : ��� ���� ����� ��� Ŭ���� �Դϴ�.
	//Cast<T> : T* ���� ĳ������ �����մϴ�
	// TArray.Add(value) : value�� �迭�� �߰��մϴ�.
}

void UGameMapWidget::SetAISimbol(int x, int y)
{
	//XY ��ġ�� TextBlock ��ü�� ��� ���� �ε����� ����մϴ�
	int32 index = (y * 3) + x;

	// index ��ġ��
	UTextBlock* textBlock = SimbolTexts[index];
	
	textBlock->SetText(FText::FromString(TEXT("O")));
}
