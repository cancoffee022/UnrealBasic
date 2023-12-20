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
	// TSubclassOf<T> : Uclass �� ���� �������� �����ϴ� ����
	// T ���İ� T ������ �Ļ� Ŭ�����鿡 ���� �����鸸 ���� �� �ִ� ����

	// ���� ���� ���� ��Ÿ���ϴ�.
	UPROPERTY()
	EGameTurn CurrentGameTurn;

	// ������ ���� ��ü�� ��Ÿ���ϴ�.
	UPROPERTY()
	class UGameMapWidget* GameMapWidgetInstance;

	// ���� ĭ�� ��Ÿ�� �迭�Դϴ�.
	TArray<FGameBoardInfo> GameBoard;

	// ���� ���� Ƚ���� ��Ÿ���ϴ�.
	UPROPERTY()
	int32 GameTurnCount;

public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void PlayerTick(float DeltaTime) override;

private:
	// ������ ���� ������ ��ȯ�մϴ�
	// out_BoardInfo : ��¿� �Ű� �����̸�, ��ȯ���� ������ ���� ���� �迭 ������ �����մϴ�.
	void GetRandomBoardInfo(FGameBoardInfo& out_BoardInfo) const;

	// xy ��ġ�� �ɺ��� ����ϴ�.
	FGameBoardInfo& GetSimbol(int32 x, int32 y);

	// XY ��ġ�� �ɺ��� �����մϴ�.
	void SetSimbol(int32 x, int32 y, int32 simbol);

	// ���� �˻��մϴ�
	bool CheckBingo(int32 x, int32 y);
};
