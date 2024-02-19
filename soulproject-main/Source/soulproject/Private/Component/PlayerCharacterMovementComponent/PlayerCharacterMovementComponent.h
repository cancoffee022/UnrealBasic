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
	// 이동 입력 허용상태를 나타냅니다
	bool AllowMovementInput;

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


	// 이동 입력 허용상태를 설정합니다
	// allowMovementInput : 허용시 true 전달
	void SetAllowMovementInput(bool allowMovementInput);

	// 충격을 가합니다
	void AddImpulse(FVector direction, float power);
		
};
