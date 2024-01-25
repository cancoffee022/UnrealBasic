// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "ChickenCharacter.generated.h"

#define BLACKBOARDKEY_MAXMOVEDISTANCE		TEXT("MaxMoveDistance")

/**
 * 
 */
UCLASS()
class AChickenCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
public:
	AChickenCharacter();

public:
	// 컨트롤러가 캐릭터에 빙의되었을 때 호출됩니다 
	virtual void PossessedBy(AController* NewController) override;

private:
	void InitializeBlackboardKey(class UBlackboardComponent* blackboardComponent);
	
};
