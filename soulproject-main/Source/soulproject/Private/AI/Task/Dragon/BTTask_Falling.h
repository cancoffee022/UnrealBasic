#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Falling.generated.h"

/**
 * 
 */
UCLASS()
class UBTTask_Falling : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	FBlackboardKeySelector TargetActorKey;

public:
	UBTTask_Falling();

protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& ownerComponent, uint8* newMemory) override;
};
