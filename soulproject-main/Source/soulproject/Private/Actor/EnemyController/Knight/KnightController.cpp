// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyController/Knight/KnightController.h"
#include "Actor/EnemyCharacter/Knight/KnightCharacter.h"

#include "Component/KnightAttackComponent/KnightAttackComponent.h"

#include "BehaviorTree/BlackboardComponent.h"

void AKnightController::OnBlackboardKeyInitialize(UBlackboardComponent* blackboardComponent, APawn* inPawn)
{
	Super::OnBlackboardKeyInitialize(blackboardComponent, inPawn);

	// MaxMoveDistance ����
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 300.f);
}

void AKnightController::Attack()
{
	// Get KnightCharcter
	AKnightCharacter* controlledCharacter = Cast<AKnightCharacter>(GetPawn());

	// ��ȿ�� �˻�
	if (!IsValid(controlledCharacter)) return;

	// ����
	controlledCharacter->GetAttackComponent()->Attack();
}
