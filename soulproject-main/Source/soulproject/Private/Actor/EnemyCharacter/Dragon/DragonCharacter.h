// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "DragonCharacter.generated.h"

#define ANIMMONTAGE_SECTION_DASHBACKWARD		TEXT("DashBackward")
#define ANIMMONTAGE_SECTION_TURNLEFT			TEXT("TurnLeft")
#define ANIMMONTAGE_SECTION_TURNRIGHT			TEXT("TurnRight")

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

protected:
	virtual void BeginPlay() override;

public:

	// �̵� �ִϸ��̼� ��Ÿ�ָ� ����մϴ�
	// playSectionName : �����ų ���� �̸�
	void PlayMoveAnimMontage(FName playSectionName);

	UFUNCTION(BlueprintCallable)
	void OnPlayerCharacterDetected(class AGameCharacter* gameCharacter);

	FORCEINLINE class UDragonCharacterMovementComponent* GetDragonMovementComponent() const
	{
		return DragonMovementComponent;
	}
	
};
