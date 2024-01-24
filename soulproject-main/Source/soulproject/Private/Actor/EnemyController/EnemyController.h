// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 적 캐릭터에서 기본적으로 사용하는 컨트롤러입니다.
 */
UCLASS()
class AEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void InitializeEnemyController(struct FEnemyData* enemyData);
};
