// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Dragon/BTTask_StartSoar.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "AnimInstance/DragonCharacter/DragonCharacterAnimInstance.h"

EBTNodeResult::Type UBTTask_StartSoar::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* newMem)
{
	ADragonCharacter* dragonCharacter = Cast<ADragonCharacter>(Cast<AController>(ownerComp.GetOwner())->GetPawn());

	UDragonCharacterMovementComponent* movementComponent = dragonCharacter->GetDragonMovementComponent();

	UDragonCharacterAnimInstance* animInst = Cast<UDragonCharacterAnimInstance>(dragonCharacter->GetMesh()->GetAnimInstance());

	movementComponent->StartFlyUp(1500);
	animInst->StartFly();
	animInst->UpdateFlyDirection(FIntVector(0, 0, 1));

	return EBTNodeResult::Type::Succeeded;
}
