// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Enum/GameTurn.h"
#include "../Struct/GameBoardInfo.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

#define SIMBOL_PLAYER		0
#define SIMBOL_AI			1
#define SIMBOL_EMPTY		2

/**
 * 
 */
UCLASS()
class AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	TSubclassOf<class UGameMapWidget> GameMapWidgetClass;
	// TSubclassOf<T> : Uclass 에 대한 안전성을 보장하는 형식
	// T 형식과 T 형식의 파생 클래스들에 대한 정보들만 담을 수 있는 형식

	// 현재 게임 턴을 나타냅니다.
	UPROPERTY()
	EGameTurn CurrentGameTurn;

	// 생성된 위젯 객체를 나타냅니다.
	UPROPERTY()
	class UGameMapWidget* GameMapWidgetInstance;

	// 게임 칸을 나타낼 배열입니다.
	TArray<FGameBoardInfo> GameBoard;

	// 게임 진행 횟수를 나타냅니다.
	UPROPERTY()
	int32 GameTurnCount;

public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void PlayerTick(float DeltaTime) override;

private:
	// 랜덤한 보드 정보를 반환합니다
	// out_BoardInfo : 출력용 매게 변수이며, 반환받을 랜덤한 보드 정보 배열 변수를 전달합니다.
	void GetRandomBoardInfo(FGameBoardInfo& out_BoardInfo) const;

	// xy 위치의 심볼을 얻습니다.
	FGameBoardInfo& GetSimbol(int32 x, int32 y);

	// XY 위치에 심볼을 설정합니다.
	void SetSimbol(int32 x, int32 y, int32 simbol);

	// 빙고를 검사합니다
	bool CheckBingo(int32 x, int32 y);
};
