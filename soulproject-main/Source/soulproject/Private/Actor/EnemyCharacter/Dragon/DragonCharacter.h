// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "DragonCharacter.generated.h"

#define ANIMMONTAGE_SECTION_DASHBACKWARD		TEXT("DashBackward")

/**
 * 
 */
UCLASS()
class ADragonCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class UAnimMontage* MoveAnimMontage;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* LeftForwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* RightForwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* LeftBackwardLeg;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* RightBackwardLeg;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UDragonCharacterMovementComponent* DragonMovementComponent;

public:
	ADragonCharacter();

public:
	// 이동 애니메이션 몽타주를 재생합니다
	void PlayMoveAnimMontage(FName playSectionName);

	UFUNCTION(BlueprintCallable)
	void OnPlayerCharacterDetected(class AGameCharacter* gameCharacter);

	FORCEINLINE class UDragonCharacterMovementComponent* GetDragonMovementComponent() const
	{
		return DragonMovementComponent;
	}
	
};
