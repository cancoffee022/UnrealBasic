#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyController/EnemyController.h"
#include "ChickenController.generated.h"

#define BLACKBOARDKEY_MAXMOVEDISTANCE		TEXT("MaxMoveDistance")

/**
 * 
 */
UCLASS()
class AChickenController : public AEnemyController
{
	GENERATED_BODY()
	
protected:
	virtual void OnBlackboardKeyInitialize(class UBlackboardComponent* blackboardComponent, class APawn* inPawn) override;
};
