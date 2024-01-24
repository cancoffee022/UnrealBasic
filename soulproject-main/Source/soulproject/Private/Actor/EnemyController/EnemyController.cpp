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
