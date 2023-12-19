// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMapWidget.h"

// UTextBlock ������� ����
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UGameMapWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Super : �θ�Ŭ������ ��Ÿ���ϴ�
	// ThisClass : �ڽ� Ŭ������ ��Ÿ���ϴ�.
	// this : �ڱ� �ڽ� ��ü�� ��Ÿ���ϴ�.

	// ���Ǵ� ������ ��� ã���ϴ�
	FindAllWidgets();

	// ��ư �̺�Ʈ�� ���ε��մϴ�.
	BindButtonEvents();
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

void UGameMapWidget::BindButtonEvents()
{
	for (int i = 0; i < SimbolTexts.Num(); ++i)
	{
		// �ؽ�Ʈ ����� �����ϴ� Button. ��ü�� ����ϴ�.
		UButton* button = Cast<UButton>(SimbolTexts[i]->GetParent());
		// WidgetInstance->GetParent() : �ش� WidgetInstance�� �����ϴ� �θ� ���� ��ü�� ����ϴ�

		// OnGameBoardClicked ��� �Լ��� ��ư �̺�Ʈ�� ���ε� �մϴ�.
		// �븮�ڿ� �Լ��� ���ε���Ű�� ���
		// Dynamic Multicast Delegate : AddDynamic(ȣ��� ���� ��ü, ����Լ� ������)
		// Dynamic Singlecast Delegate : BindDynamic(ȣ��� ���� ��ü, ����Լ� ������)
		// Multicast Delegate : Add(ȣ��� ���� ��ü, ����Լ� ������)
		// Singlecast Delegate : Bind(ȣ��� ���� ��ü, ����Լ� ������)
		button->OnClicked.AddDynamic(this, &UGameMapWidget::OnGameBoardClicked);
	}
}

void UGameMapWidget::OnGameBoardClicked()
{
	// �α� ���
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked"));
	// � ��ư�� Ŭ���Ǿ����� Ȯ���մϴ�.

}

void UGameMapWidget::SetAISimbol(int x, int y)
{
	//XY ��ġ�� TextBlock ��ü�� ��� ���� �ε����� ����մϴ�
	int32 index = (y * 3) + x;

	// index ��ġ��
	UTextBlock* textBlock = SimbolTexts[index];
	
	textBlock->SetText(FText::FromString(TEXT("O")));
}
