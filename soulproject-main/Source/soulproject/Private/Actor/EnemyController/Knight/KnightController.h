// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/EnemyController/EnemyController.h"
#include "Perception/AIPerceptionTypes.h"
#include "KnightController.generated.h"

#define KEYNAME_ISATTACKING			TEXT("IsAttacking")

DECLARE_EVENT(AKnightController, FSigntDetectedEvent)

/**
 * 
 */
UCLASS()
class AKnightController : public AEnemyController
{
	GENERATED_BODY()

public:
	FSigntDetectedEvent OnSightDetected;
	FSigntDetectedEvent OnSightLose;

private:
	class UBlackboardComponent* BlackboardComponent;

	class UAISenseConfig_Sight* AISightConfig;
	
public:
	virtual void OnBlackboardKeyInitialize(class UBlackboardComponent* blackboardComponent, class APawn* inPawn);

public:
	AKnightController();
	void Attack();
	void OnAttackFinished();

private:
	// �þ� ���� ���°� ���� �� ������ �߻��ϴ� �̺�Ʈ�� ���ε� �Ǵ� �Լ�
	UFUNCTION()
	void OnSightUpdated(class AActor* actor, FAIStimulus stimulus);
};
