// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyController/Wolf/WolfController.h"
#include "Actor/EnemyCharacter/Wolf/WolfCharacter.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Component/WolfAttackComponent/WolfAttackComponent.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

void AWolfController::OnBlackboardKeyInitialize(UBlackboardComponent* blackboardComponent, APawn* inPawn)
{
	Super::OnBlackboardKeyInitialize(blackboardComponent, inPawn);

	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 800.f);
}

AWolfController::AWolfController()
{

}

void AWolfController::Attack()
{
	AWolfCharacter* wolfCharacter = Cast<AWolfCharacter>(GetPawn());

	if (!IsValid(wolfCharacter)) return;

	wolfCharacter->GetAttackComponent()->Attack();
}

void AWolfController::OnAttackFinished()
{
	GetBlackboardComponent()->SetValueAsBool(BLACKBOARDKEY_ISATTACKING, false);
}

void AWolfController::OnOtherWolfDamaged(AGameCharacter* gameCharacter)
{
	GetBlackboardComponent()->SetValueAsBool(BLACKBOARDKEY_ISAGGRESSIVESTATE, true);
	GetBlackboardComponent()->SetValueAsObject(BLACKBOARDKEY_DAMAGEACTOR, gameCharacter);
}
