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

	// ��ǥ Yaw ȸ����
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

	// ��� ���� ����մϴ�
	void CheckDashFinish();

	void FlyMovement(float dt);

public:
	// ��ǥ Yaw ȸ������ �����մϴ�.
	void SetTargetYawAngle(float targetYawAngle);

	// ������ ��ǥ Yaw�� ȸ����ŵ�ϴ�
	void StartTurn();

	// ������ ���̷� ���ƿ�����
	void StartFlyUp(float targetHeight);
	
	// �������� �����մϴ�
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
