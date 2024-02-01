// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyController/Knight/KnightController.h"

#include "BehaviorTree/BlackboardComponent.h"

void AKnightController::OnBlackboardKeyInitialize(UBlackboardComponent* blackboardComponent, APawn* inPawn)
{
	Super::OnBlackboardKeyInitialize(blackboardComponent, inPawn);

	// MaxMoveDistance ¼³Á¤
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 300.f);
}
