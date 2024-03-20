#include "AI/Task/Dragon/BTTask_ClawAttack.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterAttackComponent/DragonCharacterAttackComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClawAttack::UBTTask_ClawAttack()
{
	// ƽ ��� Ȱ��ȭ
	bNotifyTick = true;
}

void UBTTask_ClawAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(OwnerComp.GetOwner())->GetPawn());

	if (!ClawAttackStarted)
	{
		if (pawn->GetDragonAttackComponent()->GetClawAttackState())
		{
			ClawAttackStarted = true;
		}
		else return;
	}

	if (ClawAttackStarted && !pawn->GetDragonAttackComponent()->GetClawAttackState())
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Type::Succeeded);
		ClawAttackStarted = false;
	}
}

EBTNodeResult::Type UBTTask_ClawAttack::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// GetPawn
	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(ownerComponent.GetOwner())->GetPawn());

	// ��ȿ�� �˻�
	if (!IsValid(pawn)) return EBTNodeResult::Type::Failed;

	// Claw Attack �ִϸ��̼� ���
	pawn->PlayAttackAnimMontage(ANIMMONTAGE_SECTION_CLAWATTACK);

	return EBTNodeResult::Type::InProgress;
}
