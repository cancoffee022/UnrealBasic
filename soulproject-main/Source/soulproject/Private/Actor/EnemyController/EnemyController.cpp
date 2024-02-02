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
	//SpawnLocation ����
	FVector spawnLocation = inPawn->GetActorLocation();
	blackboardComponent->SetValueAsVector(BLACKBOARDKEY_SPAWNLOCATION, spawnLocation);

	// ������ ���°� Ǯ������� �ɸ��� �ð� ����
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_TIMETOCALMDOWN, 10.f);
}

void AEnemyController::OnPossess(APawn* inPawn)
{
	Super::OnPossess(inPawn);

	// GetBlackboardComponent
	BlackboardComponent = GetBlackboardComponent();

	// ������ Ű �ʱ�ȭ
	OnBlackboardKeyInitialize(BlackboardComponent, inPawn);
}

void AEnemyController::InitializeEnemyController(FEnemyData* enemyData)
{
	if (enemyData == nullptr) return;

	FStreamableManager& streamableManager = UAssetManager::GetStreamableManager();

	// BehaviorTree ������ ����ε� ��ŵ�ϴ�
	UBehaviorTree* btAsset = Cast<UBehaviorTree>(streamableManager.LoadSynchronous(
		enemyData->BehaviorTreeAsset.ToSoftObjectPath()));

	// �ε�� BehaviorTree ���¿� ���� ������ �˻縦 �����մϴ�.
	if (IsValid(btAsset))
	{
		// �ൿƮ���� �����մϴ�.
		RunBehaviorTree(btAsset);

		UE_LOG(LogTemp, Warning, TEXT("Start BehaviorTree!"));
	}
}

void AEnemyController::OnDamaged(AGameCharacter* gameCharacter, float damage)
{
	if (!IsValid(BlackboardComponent)) return;

	// �������� ���·� ����
	BlackboardComponent->SetValueAsBool(BLACKBOARDKEY_ISAGGRESSIVESTATE, true);

	// ���ݴ��� �ð� ����
	float currentTimeSeconds = UGameplayStatics::GetTimeSeconds(this);
	BlackboardComponent->SetValueAsFloat(BLACKBOARDKEY_LASTDAMAGEDTIME, currentTimeSeconds);

	// ������ ���� ����(GameCharacter ����)
	BlackboardComponent->SetValueAsObject(BLACKBOARDKEY_DAMAGEACTOR, gameCharacter);
}

void AEnemyController::OnDead()
{
	BlackboardComponent->SetValueAsBool(BLACKBOARDKEY_ISDEAD, true);
}
