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
	// ��Ʈ�ѷ��� ĳ���Ϳ� ���ǵǾ��� �� ȣ��˴ϴ� 
	virtual void PossessedBy(AController* NewController) override;

private:
	void InitializeBlackboardKey(class UBlackboardComponent* blackboardComponent);
	
};
