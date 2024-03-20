#include "AI/Service/BTService_GetPlayerLocation.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_GetPlayerLocation::UBTService_GetPlayerLocation()
{
	PlayerActorKey.AddObjectFilter(
		this, 
		GET_MEMBER_NAME_CHECKED(ThisClass, PlayerActorKey),
		UObject::StaticClass());
	TargetLocationKey.AddVectorFilter(this,
		GET_MEMBER_NAME_CHECKED(ThisClass, TargetLocationKey));
}

void UBTService_GetPlayerLocation::TickNode(
	UBehaviorTreeComponent& ownerComponent,
	uint8* nodeMemory,
	float dt)
{
	Super::TickNode(ownerComponent, nodeMemory, dt);

	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();
	AGameCharacter* gameCharacter =
		Cast<AGameCharacter>(blackboardComponent->GetValueAsObject(PlayerActorKey.SelectedKeyName));

	// ���� �÷��̾� ĳ���Ͱ� ��ȿ���� ���� ���, �ൿ ���� 
	if (!IsValid(gameCharacter)) return;

	AController* enemyController = Cast<AController>(blackboardComponent->GetOwner());
	FVector currentLocation = enemyController->GetPawn()->GetActorLocation();

	FVector targetLocation = gameCharacter->GetActorLocation();

	if(bUseMaxTrackingDistance)
	{ 
		// �ִ� �����Ÿ�
		float maxTrackingDistance = 500.f;

		// ��ǥ��ġ������ �Ÿ��� �ִ����� �Ÿ��� �ʰ��ϴ����� Ȯ��
		if (FVector::Distance(currentLocation, targetLocation) > maxTrackingDistance)
		{
			// ��ǥ ��ġ������ ������ ����ϴ�
			FVector direction = (targetLocation - currentLocation).GetSafeNormal();

			//�ִ� �����Ÿ��� �����մϴ�
			targetLocation = currentLocation + direction * maxTrackingDistance;
		}
	}

	// ��ǥ ��ġ�� �����մϴ�
	blackboardComponent->SetValueAsVector(TargetLocationKey.SelectedKeyName, targetLocation);
}
