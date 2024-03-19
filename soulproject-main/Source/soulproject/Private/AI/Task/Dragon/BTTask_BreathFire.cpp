#include "AI/Task/Dragon/BTTask_BreathFire.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterAttackComponent/DragonCharacterAttackComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_BreathFire::UBTTask_BreathFire()
{

	// 틱 기능 활성화
	bNotifyTick = true;
}

void UBTTask_BreathFire::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(OwnerComp.GetOwner())->GetPawn());

	if (!BreathFireStarted)
	{
		if (pawn->GetDragonAttackComponent()->GetBreathFireState())
			BreathFireStarted = true;
		else return;
	}

	if (BreathFireStarted && !pawn->GetDragonAttackComponent()->GetBreathFireState())
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Type::Succeeded);
		BreathFireStarted = false;
	}
}

EBTNodeResult::Type UBTTask_BreathFire::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	AController* controller = Cast<AController>(ownerComponent.GetOwner());
	if (!IsValid(controller)) return EBTNodeResult::Type::Failed;

	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(controller->GetPawn());
	if (!IsValid(dragonCharacter)) return EBTNodeResult::Type::Failed;

	// 애니메이션 재생
	dragonCharacter->PlayAttackAnimMontage(ANIMMONTAGE_SECTION_BREATHFIRE);

	return EBTNodeResult::Type::InProgress;
}
