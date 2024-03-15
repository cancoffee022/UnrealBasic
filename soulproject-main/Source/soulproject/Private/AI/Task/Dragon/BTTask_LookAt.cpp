// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Dragon/BTTask_LookAt.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_LookAt::UBTTask_LookAt()
{
	TargetActorKey.AddObjectFilter(
		this,
		GET_MEMBER_NAME_CHECKED(ThisClass, TargetActorKey),
		UObject::StaticClass());
}

EBTNodeResult::Type UBTTask_LookAt::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	UBlackboardComponent* blackboarComponent = ownerComponent.GetBlackboardComponent();

	// 타깃 액터를 얻습니다.
	UObject* targetActorObject = blackboarComponent->GetValueAsObject(TargetActorKey.SelectedKeyName);

	// 유효성 검사
	if (!IsValid(targetActorObject)) return EBTNodeResult::Failed;
	AActor* targetActor = Cast<AActor>(targetActorObject);

	// 컨트롤러를 얻습니다
	AController* ownerController = Cast<AController>(blackboarComponent->GetOwner());
	
	// 유효성 검사
	if (!IsValid(ownerController)) return EBTNodeResult::Failed;

	//컨트롤러가 조종하는 액터
	ADragonCharacter* controlledPawn = Cast<ADragonCharacter>(ownerController->GetPawn());

	// 해당하는 액터로 향하는 방향 얻기
	FVector direction = targetActor->GetActorLocation() - controlledPawn->GetActorLocation();
	direction.Z = 0;
	direction = direction.GetSafeNormal();

	// 각도를 계산
	float yawAngle = FMath::RadiansToDegrees(FMath::Atan2(direction.Y, direction.X));

	// 계산한 각도 설정
	controlledPawn->GetDragonMovementComponent()->SetTargetYawAngle(yawAngle);

	/*if (!FMath::IsNearlyEqual(yawAngle, controlledPawn->GetActorRotation().Yaw))
	{

	}*/

	controlledPawn->PlayMoveAnimMontage(
		yawAngle > 0 ?
		ANIMMONTAGE_SECTION_TURNRIGHT : ANIMMONTAGE_SECTION_TURNLEFT);

	return EBTNodeResult::Type::Succeeded;
}
