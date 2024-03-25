#include "AI/Task/Dragon/BTTask_Falling.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"
#include "AnimInstance/DragonCharacter/DragonCharacterAnimInstance.h"
#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

UBTTask_Falling::UBTTask_Falling()
{
	TargetActorKey.AddObjectFilter(this, 
		GET_MEMBER_NAME_CHECKED(ThisClass, TargetActorKey),
		UObject::StaticClass());

	bNotifyTick = true;
}

void UBTTask_Falling::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(
		Cast<AController>(OwnerComp.GetOwner())->GetPawn());

	UDragonCharacterMovementComponent* movementComponent = dragonCharacter->GetDragonMovementComponent();

	UDragonCharacterAnimInstance* animInst = Cast<UDragonCharacterAnimInstance>(dragonCharacter->GetMesh()->GetAnimInstance());

	if (!movementComponent->GetFlyState())
	{
		animInst->FinishFlying();
		FinishLatentTask(OwnerComp, EBTNodeResult::Type::Succeeded);
	}
}

EBTNodeResult::Type UBTTask_Falling::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(	Cast<AController>(ownerComponent.GetOwner())->GetPawn());

	UDragonCharacterMovementComponent* movementComponent = dragonCharacter->GetDragonMovementComponent();

	UDragonCharacterAnimInstance* animInst = Cast<UDragonCharacterAnimInstance>(dragonCharacter->GetMesh()->GetAnimInstance());

	animInst->StartFalling();
	movementComponent->StartFalling();

	return EBTNodeResult::Type::InProgress;
}
