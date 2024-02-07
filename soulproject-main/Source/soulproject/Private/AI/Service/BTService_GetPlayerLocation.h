// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_GetPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class UBTService_GetPlayerLocation : public UBTService
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector PlayerActorKey;
	
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetLocationKey;

public:
	UBTService_GetPlayerLocation();

	virtual void TickNode(
		UBehaviorTreeComponent& ownerComponent,
		uint8* nodeMemory,
		float dt) override;
};
