#include "AI/Task/Common/BTTask_UpdateDistanceToPlayer.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_UpdateDistanceToPlayer::UBTTask_UpdateDistanceToPlayer()
{
	PlayerCharacterActorKey.AddObjectFilter(this,GET_MEMBER_NAME_CHECKED(ThisClass,PlayerCharacterActorKey),UObject::StaticClass());

	DistanceToPlayerKey.AddFloatFilter(this,GET_MEMBER_NAME_CHECKED(ThisClass,DistanceToPlayerKey));
}

EBTNodeResult::Type UBTTask_UpdateDistanceToPlayer::ExecuteTask(
	UBehaviorTreeComponent& ownerComponent, uint8* newMemory)
{
	// Get BlackboardComponent
	UBlackboardComponent* blackboardComponent = ownerComponent.GetBlackboardComponent();

	// 이 행동을 실행하는 객체 (컨트롤러)
	AController* owenrController = Cast<AController>(ownerComponent.GetOwner());

	// 유효성 검사
	if (!IsValid(owenrController)) return EBTNodeResult::Type::Failed;

	// 이 행동을 실행하는 액터 (적 캐릭터)
	AActor* controlledPawn = owenrController->GetPawn();

	// 유효성 검사
	if (!IsValid(controlledPawn)) return EBTNodeResult::Type::Failed;

	// 플레이어 캐릭터 액터
	UObject* value = blackboardComponent->GetValueAsObject(PlayerCharacterActorKey.SelectedKeyName);

	// 유효성 검사
	if (!IsValid(value)) return EBTNodeResult::Type::Failed;
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(value);

	// 거리를 검사합니다
	FVector gameCharacterLocation = gameCharacter->GetActorLocation();
	gameCharacterLocation.Z = 0;

	FVector ownerCharacterLocation = controlledPawn->GetActorLocation();
	ownerCharacterLocation.Z = 0;

	// 계산된 거리를 키에 설정합니다
	float distance = FVector::Distance(gameCharacterLocation, ownerCharacterLocation);
	blackboardComponent->SetValueAsFloat(
		DistanceToPlayerKey.SelectedKeyName,
		distance);

	// 행동 실행 성공
	return EBTNodeResult::Type::Succeeded;
}
