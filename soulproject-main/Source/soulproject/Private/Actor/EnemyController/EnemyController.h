// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * �� ĳ���Ϳ��� �⺻������ ����ϴ� ��Ʈ�ѷ��Դϴ�.
 */
UCLASS()
class AEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void InitializeEnemyController(struct FEnemyData* enemyData);
};
