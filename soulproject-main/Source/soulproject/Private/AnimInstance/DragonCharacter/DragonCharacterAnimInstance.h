#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DragonCharacterAnimInstance.generated.h"

DECLARE_EVENT(ThisClass, FDragonCharacterSingleEvent)

/**
 * 
 */
UCLASS()
class UDragonCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	FDragonCharacterSingleEvent OnTurn;

private:
	UFUNCTION()
	void AnimNotify_TurnLeft();

	UFUNCTION()
	void AnimNotify_TurnRight();
	
};
