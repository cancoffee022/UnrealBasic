// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "WolfCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AWolfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	class UWolfAttackComponent* AttackComponent;
	
public:
	AWolfCharacter();

	virtual void Tick(float dt) override;

private:
	// �ִ� �ν��Ͻ� �Ķ���� ����
	void UpdateAnimInstanceParams();

	FORCEINLINE class UWolfAttackComponent* GetAttackComponent() const
	{
		return AttackComponent;
	}
};
