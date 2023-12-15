// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MyPlayerController.h"

#include "../Widget/GameMapWidget.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FClassFinder<UGameMapWidget> WIDGETBP_GAMEMAP(
		TEXT("/ Script / UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/WidgetBP_GameMap.WidgetBP_GameMap_C'"));

	// 클래스를 얻어오는 경로에서는 항상 _C 를 작성해야 합니다.
	// WIDGETBP_GAMEMAP 블루 프린트 클래스를 성공적으로 불러왔는지 확인합니다
	if (WIDGETBP_GAMEMAP.Succeeded())
	{
		GameMapWidgetClass = WIDGETBP_GAMEMAP.Class;
		// WIDGET_GAMEMAP.Class : WIDGETBP_GAMEMAP 에 담긴 클래스를 얻습니다
	}

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}
