// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyController/EnemyController.h"
#include "KnightController.generated.h"

/**
 * 
 */
UCLASS()
class AKnightController : public AEnemyController
{
	GENERATED_BODY()
	
public:
	virtual void OnBlackboardKeyInitialize(class UBlackboardComponent* blackboardComponent, class APawn* inPawn);


public:
	void Attack();

};
