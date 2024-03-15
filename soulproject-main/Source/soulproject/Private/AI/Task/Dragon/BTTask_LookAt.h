// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_LookAt.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_LookAt : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetActorKey;


public:
	UBTTask_LookAt();

	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& ownerComponent, uint8* newMemory) override;
	
};
