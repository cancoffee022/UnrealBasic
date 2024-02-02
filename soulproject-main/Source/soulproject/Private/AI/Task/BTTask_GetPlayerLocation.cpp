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

	// 얻은 플레이어 캐릭터가 유효하지 않은 경우, 행동 실패 
	if (!IsValid(gameCharacter)) return EBTNodeResult::Failed;

	AController* enemyController = Cast<AController>(blackboardComponent->GetOwner());
	FVector currentLocation = enemyController->GetPawn()->GetActorLocation();

	FVector targetLocation = gameCharacter->GetActorLocation();

	// 최대 추적거리
	float maxTrackingDistance = 50.f;

	// 목표위치까지의 거리가 최대추적 거리를 초과하는지를 확인
	if (FVector::Distance(currentLocation, targetLocation) > maxTrackingDistance)
	{
		// 목표 위치까지의 방향을 얻습니다
		FVector direction = (targetLocation - currentLocation).GetSafeNormal();

		//최대 추적거리를 적용합니다
		targetLocation = currentLocation + direction * maxTrackingDistance;
	}

	// 목표 위치를 설정합니다
	blackboardComponent->SetValueAsVector(TargetLocationKey.SelectedKeyName, targetLocation);
	
	// 행동 성공
	return EBTNodeResult::Succeeded;
}
