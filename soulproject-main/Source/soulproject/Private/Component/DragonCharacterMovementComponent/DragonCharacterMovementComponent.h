// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DragonCharacterMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDragonCharacterMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class ADragonCharacter* DragonCharacter;

	UPROPERTY()
	bool IsDash;

public:	
	// Sets default values for this component's properties
	UDragonCharacterMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	// 대시 끝을 대기합니다
	void CheckDashFinish();

public:	
	void StartDash(FVector direction, float power);

	FORCEINLINE bool GetDashState() const
	{
		return IsDash;
	}
		
};
