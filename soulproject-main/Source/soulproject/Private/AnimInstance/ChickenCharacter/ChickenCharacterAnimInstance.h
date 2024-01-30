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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsDead;

public:
	void SetIsDead(bool isDead);
	void SetCurrentSpeed(float newSpeed);
};
