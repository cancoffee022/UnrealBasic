// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "ChickenCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AChickenCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

private:
	class UAnimMontage* OnHitAnimMontage;

public:
	AChickenCharacter();

private:
	class UChickenCharacterAnimInstance* ControlledAnimInstance;

protected:
	virtual void BeginPlay() override;

public:
	// 컨트롤러가 캐릭터에 빙의되었을 때 호출됩니다 
	virtual void PossessedBy(AController* NewController) override;
	virtual void Tick(float dt) override;


	void SetAnimInstance(UChickenCharacterAnimInstance* controlledAnimInstance);

protected:
	virtual void OnDamaged(class AGameCharacter* gameCharacter, float damage) override;

private:
	void InitializeBlackboardKey(class UBlackboardComponent* blackboardComponent);

	
};
