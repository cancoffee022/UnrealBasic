// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Knight/BTTask_KnightAttack.h"
#include "Actor/EnemyController/Knight/KnightController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"

EBTNodeResult::Type UBTTask_KnightAttack::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// Get KnightController
	AKnightController* controller= Cast<AKnightController>(ownerComponent.GetOwner());

	// 컨트롤러 객체가 유효하지 않은 경우 행동 실패
	if (!IsValid(controller)) return EBTNodeResult::Failed;

	// 공격 실행
	controller->Attack();

	// 행동 성곡
	return EBTNodeResult::Succeeded;
}
