// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Wolf/BTTask_WolfAttack.h"

#include "Actor/EnemyCharacter/Wolf/WolfCharacter.h"
#include "Actor/EnemyController/Wolf/WolfController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_WolfAttack::UBTTask_WolfAttack()
{
	IsAttackRequestedKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackRequestedKey));
	IsAttackingKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackingKey));
}

EBTNodeResult::Type UBTTask_WolfAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// ������ ������Ʈ�� ����ϴ�
	UBlackboardComponent* blackboarComponent = OwnerComp.GetBlackboardComponent();

	// ���� ��û ó����
	blackboarComponent->SetValueAsBool(IsAttackRequestedKey.SelectedKeyName, false);
	
	// ������ ���·� �����մϴ�
	blackboarComponent->SetValueAsBool(IsAttackingKey.SelectedKeyName, true);

	// Get Wolf Controller
	AWolfController* wolfController = Cast<AWolfController>(OwnerComp.GetOwner());

	// ��ȿ�� �˻� ����
	if (!IsValid(wolfController)) return EBTNodeResult::Failed;

	// ���� ����
	wolfController->Attack();

	return EBTNodeResult::Succeeded;
}
