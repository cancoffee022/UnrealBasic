// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyController/EnemyController.h"
#include "DragonController.generated.h"

#define KEYNAME_PLAYERCHARACTER			TEXT("PlayerCharacter")
#define KEYNAME_ISMOVETASKRUNNING		TEXT("IsMoveTaskRunning")
/**
 * 
 */
UCLASS()
class ADragonController : public AEnemyController
{
	GENERATED_BODY()


public:
	void SetPlayerCharacterKey(class AGameCharacter* playerCharacter);

	UFUNCTION()
	void OnDashFinished();
	
};
