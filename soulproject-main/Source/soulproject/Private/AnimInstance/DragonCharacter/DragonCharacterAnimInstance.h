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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsFly;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FIntVector FlyDirection;


public:
	FDragonCharacterSingleEvent OnTurn;
	FDragonCharacterSingleEvent OnDashFinished;

	FDragonCharacterSingleEvent OnBreathFireFinished;
	FDragonCharacterSingleEvent OnBreathFireStarted;

	FDragonCharacterSingleEvent OnClawAttackStarted;
	FDragonCharacterSingleEvent OnClawAttackFinished;

	FDragonCharacterSingleEvent OnRushAttackStarted;
	FDragonCharacterSingleEvent OnRushAttackFinished;


public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void StartFly();
	void UpdateFlyDirection(FIntVector direction);

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
	
	UFUNCTION()
	void AnimNotify_OnRushAttackStarted();

	UFUNCTION()
	void AnimNotify_OnRushAttackFinished();
};
