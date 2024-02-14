// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "KnightCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AKnightCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UKnightAttackComponent* AttackComponent;
	
public:
	AKnightCharacter();

public:
	virtual void Tick(float dt) override;

private:
	// �ִ� �ν��Ͻ� �Ķ���� ����
	void UpdateAnimInstanceParams();

public:
	// ���� ������Ʈ�� ��ȯ�մϴ�
	FORCEINLINE class UKnightAttackComponent* GetAttackComponent() const
	{ return AttackComponent; }
};