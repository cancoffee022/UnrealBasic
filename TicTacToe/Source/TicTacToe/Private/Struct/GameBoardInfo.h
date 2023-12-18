// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameBoardInfo.generated.h"

/**
 * 
 */
USTRUCT()
struct FGameBoardInfo
{
	GENERATED_USTRUCT_BODY()
	// 구조체의 경우 GENERATED_USTRUCT_BODY()를 작성합니다.

public:
	// 배열 인덱스
	UPROPERTY()
	int ArrayIndex;

	// 이 데이터가 나타내는 게임 칸 인덱스
	UPROPERTY()
	int X;

	UPROPERTY()
	int Y;

	// 설정된 심볼
	UPROPERTY()
	int Simbol;
};
