// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameMapWidget.h"

// UTextBlock 헤더파일 포함
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UGameMapWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Super : 부모클래스를 나타냅니다
	// ThisClass : 자신 클래스를 나타냅니다.
	// this : 자기 자신 객체를 나타냅니다.

	// 사용되는 위젯을 모두 찾습니다
	FindAllWidgets();

	// 버튼 이벤트를 바인딩합니다.
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
	// GetWidgetFromName(NameData) : NameData에 해당하는 위젯을 찾아 UWidget* 형식으로 반환합니다
	// UWidget 클래스 : 모든 위젯 요소의 기반 클래스 입니다.
	//Cast<T> : T* 으로 캐스팅을 진행합니다
	// TArray.Add(value) : value를 배열에 추가합니다.
}

void UGameMapWidget::BindButtonEvents()
{
	for (int i = 0; i < SimbolTexts.Num(); ++i)
	{
		// 텍스트 블록을 소유하는 Button. 객체를 얻습니다.
		UButton* button = Cast<UButton>(SimbolTexts[i]->GetParent());
		// WidgetInstance->GetParent() : 해당 WidgetInstance를 소유하는 부모 위젯 객체를 얻습니다

		// OnGameBoardClicked 멤버 함수를 버튼 이벤트에 바인딩 합니다.
		// 대리자에 함수를 바인딩시키는 방법
		// Dynamic Multicast Delegate : AddDynamic(호출시 사용될 객체, 멤버함수 포인터)
		// Dynamic Singlecast Delegate : BindDynamic(호출시 사용될 객체, 멤버함수 포인터)
		// Multicast Delegate : Add(호출시 사용될 객체, 멤버함수 포인터)
		// Singlecast Delegate : Bind(호출시 사용될 객체, 멤버함수 포인터)
		button->OnClicked.AddDynamic(this, &UGameMapWidget::OnGameBoardClicked);
	}
}

void UGameMapWidget::OnGameBoardClicked()
{
	// 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked"));
	// 어떤 버튼이 클릭되었는지 확인합니다.

}

void UGameMapWidget::SetAISimbol(int x, int y)
{
	//XY 위치의 TextBlock 객체를 얻기 위한 인덱스를 계산합니다
	int32 index = (y * 3) + x;

	// index 위치에
	UTextBlock* textBlock = SimbolTexts[index];
	
	textBlock->SetText(FText::FromString(TEXT("O")));
}
