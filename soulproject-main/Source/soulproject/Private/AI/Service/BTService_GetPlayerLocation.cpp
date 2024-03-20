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

	// 얻은 플레이어 캐릭터가 유효하지 않은 경우, 행동 실패 
	if (!IsValid(gameCharacter)) return;

	AController* enemyController = Cast<AController>(blackboardComponent->GetOwner());
	FVector currentLocation = enemyController->GetPawn()->GetActorLocation();

	FVector targetLocation = gameCharacter->GetActorLocation();

	if(bUseMaxTrackingDistance)
	{ 
		// 최대 추적거리
		float maxTrackingDistance = 500.f;

		// 목표위치까지의 거리가 최대추적 거리를 초과하는지를 확인
		if (FVector::Distance(currentLocation, targetLocation) > maxTrackingDistance)
		{
			// 목표 위치까지의 방향을 얻습니다
			FVector direction = (targetLocation - currentLocation).GetSafeNormal();

			//최대 추적거리를 적용합니다
			targetLocation = currentLocation + direction * maxTrackingDistance;
		}
	}

	// 목표 위치를 설정합니다
	blackboardComponent->SetValueAsVector(TargetLocationKey.SelectedKeyName, targetLocation);
}
