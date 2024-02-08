// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyController/EnemyController.h"
#include "KnightController.generated.h"

#define KEYNAME_ISATTACKING			TEXT("IsAttacking")

/**
 * 
 */
UCLASS()
class AKnightController : public AEnemyController
{
	GENERATED_BODY()

private:
	class UBlackboardComponent* BlackboardComponent;
	
public:
	virtual void OnBlackboardKeyInitialize(class UBlackboardComponent* blackboardComponent, class APawn* inPawn);


public:
	void Attack();
	void OnAttackFinished();

};
