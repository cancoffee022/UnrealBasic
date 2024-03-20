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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float XYSpeed;



public:
	FDragonCharacterSingleEvent OnTurn;
	FDragonCharacterSingleEvent OnDashFinished;

	FDragonCharacterSingleEvent OnBreathFireFinished;
	FDragonCharacterSingleEvent OnBreathFireStarted;

	FDragonCharacterSingleEvent OnClawAttackStarted;
	FDragonCharacterSingleEvent OnClawAttackFinished;

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UFUNCTION()
	void AnimNotify_TurnLeft();

	UFUNCTION()
	void AnimNotify_TurnRight();

	UFUNCTION()
	void AnimNotify_DashFinished();

	UFUNCTION()
	void AnimNotify_OnBreathFireStarted();
	
	UFUNCTION()
	void AnimNotify_OnBreathFireFinished();
	
	UFUNCTION()
	void AnimNotify_OnClawAttackStarted();

	UFUNCTION()
	void AnimNotify_OnClawAttackFinished();
};
