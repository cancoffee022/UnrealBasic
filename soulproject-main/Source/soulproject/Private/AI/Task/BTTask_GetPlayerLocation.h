// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GetPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_GetPlayerLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector PlayerActorKey;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetLocationKey;

public:
	UBTTask_GetPlayerLocation();

	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory) override;
};
