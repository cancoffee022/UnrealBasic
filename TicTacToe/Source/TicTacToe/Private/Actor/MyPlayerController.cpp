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

	// 테스트를 위해 AI 턴으로 설정
	CurrentGameTurn = EGameTurn::Turn_AI;

	// 위젯 객체를 생성합니다
	GameMapWidgetInstance = CreateWidget<UGameMapWidget>(this, GameMapWidgetClass);
	// CreateWidget<T>(owningObj, WidgetClass)
	// T : 생성된 객체의 형식을 지정합니다.
	// owningObj : 생성된 위젯 잭체를 소유할 객체를 전달합니다
	// widgetClass : 생성할 위젯 클래스를 전달합니다.

	// 화면에 생성된 Widget을 띄웁니다.
	GameMapWidgetInstance->AddToViewport();

	OnPlayerSimbolUpdated_Signature onPlayerSimbolUpdated;
	onPlayerSimbolUpdated.BindLambda([&](int32 x, int32 y)
		{
			// 심볼 존재여부 검사 진행후 처리

			// 플레이어 심볼을 설정합니다
			SetSimbol(x, y, SIMBOL_PLAYER);

			// AI턴으로 넘깁니다
			CurrentGameTurn = EGameTurn::Turn_AI;

			// 턴을 1ㅈ증가시킵니다
			++GameTurnCount;
		});

	GameMapWidgetInstance->SetPlayerSimbolUpdatedEvent(onPlayerSimbolUpdated);

	// 커서를 표시합니다
	bShowMouseCursor = true;

	// 게임 칸을 초기화 합니다
	for (int i = 0; i < 9; i++)
	{
		// 보드 정보를 생성합니다
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

	if (CurrentGameTurn == EGameTurn::Turn_AI)
	{
		// 심볼이 설정된 요소들을 맨 앞으로 이동시킨 배열을 생성합니다.

		// 남은 칸 중에서 하나를 뽑습니다.
		FGameBoardInfo randomBoardInfo;
		GetRandomBoardInfo(randomBoardInfo);

		// 랜덤한 위체에 AI 심볼을 설정합니다
		GameMapWidgetInstance->SetAISimbol(randomBoardInfo.X, randomBoardInfo.Y);

		// AI 심볼을 설정합니다
		SetSimbol(randomBoardInfo.X, randomBoardInfo.Y, SIMBOL_AI);

		// 턴을 1 증가시킵니다.
		++GameTurnCount;

		// 플레이어 턴으로 교체합니다.
		CurrentGameTurn = EGameTurn::Turn_Player;
	}
}

void AMyPlayerController::GetRandomBoardInfo(FGameBoardInfo& out_BoardInfo) const
{
	TArray<FGameBoardInfo> copiedBoardInfo = GameBoard;

	// 교환의 첫 번째 대상을 선택할 for 문
	for (int32 target = 0; target < copiedBoardInfo.Num() - 1; ++target)
	{
		// 교환의 두번째 대상을 선택할 for 문
		for (int32 i = target + 1; i < copiedBoardInfo.Num(); i++)
		{
			// 심볼이 설정된 요소인 경우 앞으로 이동시킵니다
			if (copiedBoardInfo[i].Simbol != SIMBOL_EMPTY)
			{
				// 교환을 위해 임시 저장
				FGameBoardInfo temp = copiedBoardInfo[i];
				copiedBoardInfo[i] = copiedBoardInfo[target];
				copiedBoardInfo[target] = temp;
			}
		}
	}

	// 랜덤한 비어있는 보드 정보를 얻습니다.
	int32 randomIndex = FMath::RandRange(GameTurnCount, copiedBoardInfo.Num() - 1);

	
	// 출력용 매개 병수에 값을 설정합니다.
	out_BoardInfo = copiedBoardInfo[randomIndex];
	
}

FGameBoardInfo& AMyPlayerController::GetSimbol(int32 x, int32 y)
{
	// 배열 요소에 접근시킬 인덱스를 계산합니다
	int32 index = x + y * 3;

	// index에 해당하는 값을 반환합니다
	return GameBoard[index];
}

void AMyPlayerController::SetSimbol(int32 x, int32 y, int32 simbol)
{
	UE_LOG(LogTemp, Warning, TEXT("[%d][%d] 위치에 심볼이 활성화되었습니다"), x, y);

	// x, y 위치의 심볼 데이터를 얻습니다
	FGameBoardInfo& gameBoardInfo = GetSimbol(x, y);

	// 심볼을 설정합니다.
	gameBoardInfo.Simbol = simbol;

	// 빙고 검사
	if (CheckBingo(x, y))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s 빙고!"),
			simbol == SIMBOL_AI ? TEXT("AI") : TEXT("PLAYER"));
	}

	// 무승부 검사
	else if (GameTurnCount == 8)
	{
		UE_LOG(LogTemp, Warning, TEXT("Draw"));
	}
	
}

bool AMyPlayerController::CheckBingo(int32 x, int32 y)
{
	// X, Y 위체이대한 심볼 정보를 얻습니다
	FGameBoardInfo& gameBoardInfo = GetSimbol(x, y);

	// 비교할 심볼을 얻습니다
	int32 simbol = gameBoardInfo.Simbol;

	// 빙고 여부를 나타내기 위한 변수
	bool isBingo = false;

	// 가로 빙고 체크
	if (GetSimbol(0, y).Simbol == simbol &&
		GetSimbol(1, y).Simbol == simbol &&
		GetSimbol(2, y).Simbol == simbol
		)
	{
		return true;
	}
	
	// 세로 빙고 체크
	if (GetSimbol(x, 0).Simbol == simbol &&
		GetSimbol(x, 1).Simbol == simbol &&
		GetSimbol(x, 2).Simbol == simbol
		)
	{
		return true;
	}
	
	// 대각선 빙고 체크 (우하양)
	if (GetSimbol(0, 0).Simbol == simbol &&
		GetSimbol(1, 1).Simbol == simbol &&
		GetSimbol(2, 2).Simbol == simbol
		)
	{
		return true;
	}
	
	// 대각선 빙고 체크 (우하양)
	if (GetSimbol(2, 0).Simbol == simbol &&
		GetSimbol(1, 1).Simbol == simbol &&
		GetSimbol(0, 2).Simbol == simbol
		)
	{
		return true;
	}
	
	
	return false;
}
