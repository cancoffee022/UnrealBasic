// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMapWidget.h"

// UTextBlock 헤더파일 포함
#include "Components/TextBlock.h"

void UGameMapWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Super : 부모클래스를 나타냅니다
	// ThisClass : 자신 클래스를 나타냅니다.
	// this : 자기 자신 객체를 나타냅니다.

	// 사용되는 위젯을 모두 찾습니다
	FindAllWidgets();

	// TODO 추후 제거해야함
	// 테스트용 코드
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
	// GetWidgetFromName(NameData) : NameData에 해당하는 위젯을 찾아 UWidget* 형식으로 반환합니다
	// UWidget 클래스 : 모든 위젯 요소의 기반 클래스 입니다.
	//Cast<T> : T* 으로 캐스팅을 진행합니다
	// TArray.Add(value) : value를 배열에 추가합니다.
}

void UGameMapWidget::SetAISimbol(int x, int y)
{
	//XY 위치의 TextBlock 객체를 얻기 위한 인덱스를 계산합니다
	int32 index = (y * 3) + x;

	// index 위치에
	UTextBlock* textBlock = SimbolTexts[index];
	
	textBlock->SetText(FText::FromString(TEXT("O")));
}
