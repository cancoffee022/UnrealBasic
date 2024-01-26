#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ChickenCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UChickenCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

public:
	void SetCurrentSpeed(float newSpeed);
};
