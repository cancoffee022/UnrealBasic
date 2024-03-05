// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterMovementComponent : public UActorComponent
{
	GENERATED_BODY()


private :
	UPROPERTY()
	class AGameCharacter* GameCharacter;

	UPROPERTY()
	class UAnimMontage* RollAnimMontage;

	// �̵� �Է� �����¸� ��Ÿ���ϴ�
	bool AllowMovementInput;

	// ������ �Էµ� ������ ����
	FIntVector2 PrevRollInputDirection;

	// ������ �Է½ð�
	float RollInputTime;

	// ���� ������������ ��Ÿ���ϴ�
	UPROPERTY()
	bool IsRollingMovement;

public:	
	UPlayerCharacterMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void HorizontalMove(float axis);
	void VerticalMove(float axis);
	void OnJump();
	void OnHit();
	void OnRollInput(FIntVector2 inputDirection);
	void OnRollFinished();

	// �̵� �Է� �����¸� �����մϴ�
	// allowMovementInput : ���� true ����
	void SetAllowMovementInput(bool allowMovementInput);

	// ����� ���մϴ�
	void AddImpulse(FVector direction, float power);

private:
	// ������ �̵��� �����մϴ�
	void RollingMovement(FVector rollDirection);
		
};
