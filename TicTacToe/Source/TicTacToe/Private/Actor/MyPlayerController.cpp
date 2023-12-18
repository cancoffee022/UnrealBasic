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

	// ���� ��ü�� �����մϴ�
	GameMapWidgetInstance = CreateWidget<UGameMapWidget>(this, GameMapWidgetClass);
	// CreateWidget<T>(owningObj, WidgetClass)
	// T : ������ ��ü�� ������ �����մϴ�.
	// owningObj : ������ ���� ��ü�� ������ ��ü�� �����մϴ�
	// widgetClass : ������ ���� Ŭ������ �����մϴ�.

	// ȭ�鿡 ������ Widget�� ���ϴ�.
	GameMapWidgetInstance->AddToViewport();

	// Ŀ���� ǥ���մϴ�
	bShowMouseCursor = true;

	// ���� ĭ�� �ʱ�ȭ �մϴ�
	for (int i = 0; i < 9; i++)
	{
		// ���� ������ �����մϴ�
		FGameBoardInfo boardInfo;
		boardInfo.Simbol = SIMBOL_EMPTY;
		boardInfo.ArrayIndex = i;
		boardInfo.X = i % 3;
		boardInfo.Y = i / 3;

		GameBoard.Add(boardInfo);
	}
}

void AMyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (CurrentGameTurn == EGameTurn::Trun_Ai)
	{
		// �ɺ��� ������ ��ҵ��� �� ������ �̵���Ų �迭�� �����մϴ�.

		// ���� ĭ �߿��� �ϳ��� �̽��ϴ�.
		FGameBoardInfo randomBoardInfo;
		GetRandomBoardInfo(randomBoardInfo);

		// ������ ��ü�� AI �ɺ��� �����մϴ�
		GameMapWidgetInstance->SetAISimbol(randomBoardInfo.X, randomBoardInfo.Y);

		// ���� 1 ������ŵ�ϴ�.
		++GameTurnCount;
	}
}

void AMyPlayerController::GetRandomBoardInfo(FGameBoardInfo& out_BoardInfo) const
{
	TArray<FGameBoardInfo> copiedBoardInfo = GameBoard;

	// ��ȯ�� ù ��° ����� ������ for ��
	for (int32 target = 0; target < copiedBoardInfo.Num() - 1; ++target)
	{

		// ��ȯ�� �ι�° ����� ������ for ��
		for (int32 i = target + 1; i < copiedBoardInfo.Num(); i++)
		{
			// �ɺ��� ������ ����� ��� ������ �̵���ŵ�ϴ�
			if (copiedBoardInfo[i].Simbol != SIMBOL_EMPTY)
			{
				// ��ȯ�� ���� �ӽ� ����
				FGameBoardInfo temp = copiedBoardInfo[i];
				copiedBoardInfo[i] = copiedBoardInfo[target];
				copiedBoardInfo[target] = temp;
			}
		}
	}

	// ������ ����ִ� ���� ������ ����ϴ�.
	int32 randomIndex = FMath::RandRange(GameTurnCount, copiedBoardInfo.Num() - 1);
	
	// ��¿� �Ű� ������ ���� �����մϴ�.
	out_BoardInfo = copiedBoardInfo[randomIndex];
	
}

FGameBoardInfo AMyPlayerController::GetSimbol(int32 x, int32 y)
{
	// �迭 ��ҿ� ���ٽ�ų �ε����� ����մϴ�
	int32 index = x + y * 3;

	// index�� �ش��ϴ� ���� ��ȯ�մϴ�
	return GameBoard[index];
}
