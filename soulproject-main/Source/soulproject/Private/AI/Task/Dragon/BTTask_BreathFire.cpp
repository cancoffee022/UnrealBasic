// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Dragon/BTTask_BreathFire.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_BreathFire::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	AController* controller = Cast<AController>(ownerComponent.GetOwner());
	if (!IsValid(controller)) return EBTNodeResult::Type::Failed;

	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(controller->GetPawn());
	if (!IsValid(dragonCharacter)) return EBTNodeResult::Type::Failed;

	// 애니메이션 재생
	dragonCharacter->PlayAttackAnimMontage(ANIMMONTAGE_SECTION_BREATHFIRE);

	return EBTNodeResult::Type::Succeeded;
}
