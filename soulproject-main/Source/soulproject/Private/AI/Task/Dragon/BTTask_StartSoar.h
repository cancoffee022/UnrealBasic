// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_StartSoar.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_StartSoar : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& ownerComp, uint8* newMem) override;
	
};