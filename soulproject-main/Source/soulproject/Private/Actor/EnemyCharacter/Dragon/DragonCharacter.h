// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "DragonCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADragonCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* LeftForwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* RightForwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* LeftBackwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* RightBackwardLeg;

public:
	ADragonCharacter();
	
};
