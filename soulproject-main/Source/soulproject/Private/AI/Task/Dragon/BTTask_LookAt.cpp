// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/Dragon/BTTask_LookAt.h"

#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"

#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_LookAt::UBTTask_LookAt()
{
	IsMoveTaskRunningKey.AddBoolFilter(this,
		GET_MEMBER_NAME_CHECKED(ThisClass, IsMoveTaskRunningKey));

	TargetActorKey.AddObjectFilter(
		this,
		GET_MEMBER_NAME_CHECKED(ThisClass, TargetActorKey),
		UObject::StaticClass());

	// 틱 기능을 활성화 시킵니다
	bNotifyTick = true;
}

void UBTTask_LookAt::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	// 컨트롤러를 얻습니다
	AController* ownerController = Cast<AController>(OwnerComp.GetOwner());

	//컨트롤러가 조종하는 액터
	ADragonCharacter* controlledPawn = Cast<ADragonCharacter>(ownerController->GetPawn());

	UDragonCharacterMovementComponent* movementComponent = controlledPawn->GetDragonMovementComponent();

	if (!YawTurningStarted)
	{
		if (movementComponent->GetYawTurningState())
		{
			YawTurningStarted = true;
		}
		else return;
	}

	if (controlledPawn->GetDragonMovementComponent()->IsYawTurnFinished())
	{ 
		FinishLatentTask(OwnerComp, EBTNodeResult::Type::Succeeded);
	}
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

	// 현재 회전과 별 차이가 없는 경우, 회전시키지 않습니다
	float currentYawAngle = controlledPawn->GetActorRotation().Yaw;
	if (FRotator(0, yawAngle, 0).Equals(FRotator(0, currentYawAngle, 0), 15.f))
	{
		return EBTNodeResult::Type::Failed;
	}

	controlledPawn->PlayMoveAnimMontage(
		yawAngle > 0 ?
		ANIMMONTAGE_SECTION_TURNRIGHT : ANIMMONTAGE_SECTION_TURNLEFT);

	return EBTNodeResult::Type::InProgress;
}
