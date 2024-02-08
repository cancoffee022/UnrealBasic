// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KnightAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UKnightAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	class UAnimMontage* AttackAnimMontage;

public:	
	// Sets default values for this component's properties
	UKnightAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Attack();
	void OnAttackFinished();
};
