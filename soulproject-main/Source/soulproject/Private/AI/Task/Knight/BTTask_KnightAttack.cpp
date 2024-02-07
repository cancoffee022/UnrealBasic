// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Knight/BTTask_KnightAttack.h"
#include "Actor/EnemyController/Knight/KnightController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"

EBTNodeResult::Type UBTTask_KnightAttack::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// Get KnightController
	AKnightController* controller= Cast<AKnightController>(ownerComponent.GetOwner());

	// ��Ʈ�ѷ� ��ü�� ��ȿ���� ���� ��� �ൿ ����
	if (!IsValid(controller)) return EBTNodeResult::Failed;

	// ���� ����
	controller->Attack();

	// �ൿ ����
	return EBTNodeResult::Succeeded;
}
