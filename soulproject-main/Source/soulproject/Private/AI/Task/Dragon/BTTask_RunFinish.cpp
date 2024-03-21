#include "AI/Task/Dragon/BTTask_RunFinish.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterAttackComponent/DragonCharacterAttackComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_RunFinish::UBTTask_RunFinish()
{
	DistanceToPlayerKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, DistanceToPlayerKey));

	bNotifyTick = true;
}

void UBTTask_RunFinish::TickTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMem, float dt)
{
	Super::TickTask(ownerComp, nodeMem, dt);

	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(ownerComp.GetOwner())->GetPawn());


	UDragonCharacterAttackComponent* attackComponent = pawn->GetDragonAttackComponent();

	if (!bRushAttackAnimationStarted)
	{
		if (attackComponent->GetRushAttackState())
			bRushAttackAnimationStarted = true;
		else return;
	}

	if (bRushAttackAnimationStarted && !attackComponent->GetRushAttackState())
	{
		bRushAttackAnimationStarted = false;
		FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	}
}

EBTNodeResult::Type UBTTask_RunFinish::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* newMem)
{
	UBlackboardComponent* blackboardComponent = ownerComp.GetBlackboardComponent();
	float distanceToPlayer = blackboardComponent->GetValueAsFloat(DistanceToPlayerKey.SelectedKeyName);

	if (distanceToPlayer >= 700)
	{
		return EBTNodeResult::Type::Failed;
	}

	ADragonCharacter* pawn = Cast<ADragonCharacter>(Cast<AController>(ownerComp.GetOwner())->GetPawn());

	// 애니메이션 재생
	pawn->PlayAttackAnimMontage(ANIMMONTAGE_SECTION_RUSHATTACK);

	return EBTNodeResult::Type::InProgress;
}
