#include "Actor/EnemyController/EnemyController.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Structure/EnemyData/EnemyData.h"

#include "Kismet/GameplayStatics.h"

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree//BehaviorTree.h"

void AEnemyController::OnBlackboardKeyInitialize(UBlackboardComponent* blackboardComponent, APawn* inPawn)
{
	//SpawnLocation 설정
	FVector spawnLocation = inPawn->GetActorLocation();
	blackboardComponent->SetValueAsVector(BLACKBOARDKEY_SPAWNLOCATION, spawnLocation);

	// 공격적 상태가 풀리기까지 걸리는 시간 설정
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_TIMETOCALMDOWN, 10.f);
}

void AEnemyController::OnPossess(APawn* inPawn)
{
	Super::OnPossess(inPawn);

	// GetBlackboardComponent
	BlackboardComponent = GetBlackboardComponent();

	// 블랙보드 키 초기화
	OnBlackboardKeyInitialize(BlackboardComponent, inPawn);
}

void AEnemyController::InitializeEnemyController(FEnemyData* enemyData)
{
	if (enemyData == nullptr) return;

	FStreamableManager& streamableManager = UAssetManager::GetStreamableManager();

	// BehaviorTree 에셋을 동기로드 시킵니다
	UBehaviorTree* btAsset = Cast<UBehaviorTree>(streamableManager.LoadSynchronous(
		enemyData->BehaviorTreeAsset.ToSoftObjectPath()));

	// 로드된 BehaviorTree 에셋에 대한 유혀성 검사를 진행합니다.
	if (IsValid(btAsset))
	{
		// 행동트릴를 실행합니다.
		RunBehaviorTree(btAsset);

		UE_LOG(LogTemp, Warning, TEXT("Start BehaviorTree!"));
	}
}

void AEnemyController::OnDamaged(AGameCharacter* gameCharacter, float damage)
{
	if (!IsValid(BlackboardComponent)) return;

	// 공격적인 상태로 설정
	BlackboardComponent->SetValueAsBool(BLACKBOARDKEY_ISAGGRESSIVESTATE, true);

	// 공격당한 시간 설정
	float currentTimeSeconds = UGameplayStatics::GetTimeSeconds(this);
	BlackboardComponent->SetValueAsFloat(BLACKBOARDKEY_LASTDAMAGEDTIME, currentTimeSeconds);

	// 공격한 액터 설정(GameCharacter 액터)
	BlackboardComponent->SetValueAsObject(BLACKBOARDKEY_DAMAGEACTOR, gameCharacter);
}

void AEnemyController::OnDead()
{
	BlackboardComponent->SetValueAsBool(BLACKBOARDKEY_ISDEAD, true);
}
