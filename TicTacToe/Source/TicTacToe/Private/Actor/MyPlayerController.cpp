// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MyPlayerController.h"

#include "../Widget/GameMapWidget.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FClassFinder<UGameMapWidget> WIDGETBP_GAMEMAP(
		TEXT("/ Script / UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/WidgetBP_GameMap.WidgetBP_GameMap_C'"));

	// Ŭ������ ������ ��ο����� �׻� _C �� �ۼ��ؾ� �մϴ�.
	// WIDGETBP_GAMEMAP ��� ����Ʈ Ŭ������ ���������� �ҷ��Դ��� Ȯ���մϴ�
	if (WIDGETBP_GAMEMAP.Succeeded())
	{
		GameMapWidgetClass = WIDGETBP_GAMEMAP.Class;
		// WIDGET_GAMEMAP.Class : WIDGETBP_GAMEMAP �� ��� Ŭ������ ����ϴ�
	}

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}
