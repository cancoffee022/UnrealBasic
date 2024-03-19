#include "AI/Task/Dragon/BTTask_ClawAttack.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterAttackComponent/DragonCharacterAttackComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClawAttack::UBTTask_ClawAttack()
{
	bNotifyTick = true;
}

void UBTTask_ClawAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (!ClawAttackStarted)
	{

	}
}

EBTNodeResult::Type UBTTask_ClawAttack::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// GetPawn
	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(ownerComponent.GetOwner())->GetPawn());

	// 유효성 검사
	if (!IsValid(pawn)) return EBTNodeResult::Type::Failed;

	// Claw Attack 애니메이션 재생
	pawn->PlayAttackAnimMontage(ANIMMONTAGE_SECTION_CLAWATTACK);

	return EBTNodeResult::Type::InProgress;
}
