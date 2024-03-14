#include "AI/Task/Dragon/BTTask_DashBackward.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"
#include "Actor/EnemyController/Dragon/DragonController.h"

#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_DashBackward::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// GetBlackboardComponent
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();

	ADragonController* controller = Cast<ADragonController>(blackboardComponent->GetOwner());
	if (!IsValid(controller)) return EBTNodeResult::Type::Failed;

	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(controller->GetPawn());
	if (!IsValid(dragonCharacter)) return EBTNodeResult::Type::Failed;

	if (!dragonCharacter->GetDragonMovementComponent()->GetDashState())
	{
		dragonCharacter->GetDragonMovementComponent()->StartDash(
			dragonCharacter->GetActorForwardVector() * -1,
			5000.0f);
	}

	return EBTNodeResult::Type::Succeeded;

}
