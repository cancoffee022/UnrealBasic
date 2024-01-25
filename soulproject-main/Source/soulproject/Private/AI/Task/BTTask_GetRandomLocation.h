// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GetRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_GetRandomLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	// 이 액터가 생성된 위치를 나타내는 Key입니다
	UPROPERTY(EditAnywhere, CateGory = Blackboard)
	FBlackboardKeySelector SpawnLocationKey;


	// 이동할 최대 거리
	UPROPERTY(EditAnywhere, CateGory = Blackboard)
	FBlackboardKeySelector MaxMoveDistance;

	// 목표가 ㅇ이동할 위치
	UPROPERTY(EditAnywhere, CateGory = Blackboard)
	FBlackboardKeySelector ResultLocationKey;

public:
	UBTTask_GetRandomLocation();
	
public:
	// 태스크 실행 이벤트입니다.
	// return 을 통해 행동이 끝났음을 나타낼 수 있으며, EBTNodeResult::Type 을 통해
	virtual EBTNodeResult::Type ExecuteTask(
	UBehaviorTreeComponent& ownerComponent, uint8* newMemory) override;

};
