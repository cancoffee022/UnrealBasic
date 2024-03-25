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
	
	UPROPERTY()
	bool IsFly;

	UPROPERTY()
	bool IsFalling;

	UPROPERTY()
	float FlyTargetHeight;

	UPROPERTY()
	FVector BodyMeshLocation;

	UPROPERTY()
	bool IsYawTurnning;

	// 목표 Yaw 회전값
	UPROPERTY()
	float TargetYawAngle;

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
	void TurnningSmooth(float dt);

	// 대시 끝을 대기합니다
	void CheckDashFinish();

	void FlyMovement(float dt);

public:
	// 목표 Yaw 회전값을 설정합니다.
	void SetTargetYawAngle(float targetYawAngle);

	// 설정된 목표 Yaw로 회전시킵니다
	void StartTurn();

	// 설정된 높이로 날아오른다
	void StartFlyUp(float targetHeight);
	
	// 떨어지기 시작합니다
	void StartFalling();

	void FinishFlying();

	void StartDash(FVector direction, float power);

	bool IsYawTurnFinished();

	FORCEINLINE bool GetDashState() const
	{
		return IsDash;
	}

	FORCEINLINE bool GetYawTurningState() const
	{
		return IsYawTurnning;
	}
		
	FORCEINLINE bool GetFlyState() const
	{
		return IsFly;
	}
};
