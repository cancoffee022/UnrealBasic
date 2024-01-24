// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyController/EnemyController.h"
#include "Structure/EnemyData/EnemyData.h"

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

#include "BehaviorTree//BehaviorTree.h"

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
