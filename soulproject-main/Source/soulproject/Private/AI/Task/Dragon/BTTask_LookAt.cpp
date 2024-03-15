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

	// Ÿ�� ���͸� ����ϴ�.
	UObject* targetActorObject = blackboarComponent->GetValueAsObject(TargetActorKey.SelectedKeyName);

	// ��ȿ�� �˻�
	if (!IsValid(targetActorObject)) return EBTNodeResult::Failed;
	AActor* targetActor = Cast<AActor>(targetActorObject);

	// ��Ʈ�ѷ��� ����ϴ�
	AController* ownerController = Cast<AController>(blackboarComponent->GetOwner());
	
	// ��ȿ�� �˻�
	if (!IsValid(ownerController)) return EBTNodeResult::Failed;

	//��Ʈ�ѷ��� �����ϴ� ����
	ADragonCharacter* controlledPawn = Cast<ADragonCharacter>(ownerController->GetPawn());

	// �ش��ϴ� ���ͷ� ���ϴ� ���� ���
	FVector direction = targetActor->GetActorLocation() - controlledPawn->GetActorLocation();
	direction.Z = 0;
	direction = direction.GetSafeNormal();

	// ������ ���
	float yawAngle = FMath::RadiansToDegrees(FMath::Atan2(direction.Y, direction.X));

	// ����� ���� ����
	controlledPawn->GetDragonMovementComponent()->SetTargetYawAngle(yawAngle);

	/*if (!FMath::IsNearlyEqual(yawAngle, controlledPawn->GetActorRotation().Yaw))
	{

	}*/

	controlledPawn->PlayMoveAnimMontage(
		yawAngle > 0 ?
		ANIMMONTAGE_SECTION_TURNRIGHT : ANIMMONTAGE_SECTION_TURNLEFT);

	return EBTNodeResult::Type::Succeeded;
}
