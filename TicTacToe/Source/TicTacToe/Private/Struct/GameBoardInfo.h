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
	// ����ü�� ��� GENERATED_USTRUCT_BODY()�� �ۼ��մϴ�.

public:
	// �迭 �ε���
	UPROPERTY()
	int ArrayIndex;

	// �� �����Ͱ� ��Ÿ���� ���� ĭ �ε���
	UPROPERTY()
	int X;

	UPROPERTY()
	int Y;

	// ������ �ɺ�
	UPROPERTY()
	int Simbol;
};
