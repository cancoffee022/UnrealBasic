#include "AI/Task/BTTask_GetPlayerLocation.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GetPlayerLocation::UBTTask_GetPlayerLocation()
{
	PlayerActorKey.AddObjectFilter(
		this, 
		GET_MEMBER_NAME_CHECKED(ThisClass, PlayerActorKey),
		AGameCharacter::StaticClass());
	TargetLocationKey.AddVectorFilter(this,
		GET_MEMBER_NAME_CHECKED(ThisClass, TargetLocationKey));
}

EBTNodeResult::Type UBTTask_GetPlayerLocation::ExecuteTask(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory)
{
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();
	AGameCharacter* gameCharacter =
		Cast<AGameCharacter>(blackboardComponent->GetValueAsObject(PlayerActorKey.SelectedKeyName));

	// ���� �÷��̾� ĳ���Ͱ� ��ȿ���� ���� ���, �ൿ ���� 
	if (!IsValid(gameCharacter)) return EBTNodeResult::Failed;

	AController* enemyController = Cast<AController>(blackboardComponent->GetOwner());
	FVector currentLocation = enemyController->GetPawn()->GetActorLocation();

	FVector targetLocation = gameCharacter->GetActorLocation();

	// �ִ� �����Ÿ�
	float maxTrackingDistance = 50.f;

	// ��ǥ��ġ������ �Ÿ��� �ִ����� �Ÿ��� �ʰ��ϴ����� Ȯ��
	if (FVector::Distance(currentLocation, targetLocation) > maxTrackingDistance)
	{
		// ��ǥ ��ġ������ ������ ����ϴ�
		FVector direction = (targetLocation - currentLocation).GetSafeNormal();

		//�ִ� �����Ÿ��� �����մϴ�
		targetLocation = currentLocation + direction * maxTrackingDistance;
	}

	// ��ǥ ��ġ�� �����մϴ�
	blackboardComponent->SetValueAsVector(TargetLocationKey.SelectedKeyName, targetLocation);
	
	// �ൿ ����
	return EBTNodeResult::Succeeded;
}
