// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHOOTER_PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

// SpringArm 컴포넌트 추가
	UPROPERTY(VisibleAnyWhere)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnyWhere)
	class UCameraComponent* CameraComponent;


public:
	// Sets default values for this character's properties
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void OnHorizontalInput(float axis);
	void OnVerticalInput(float axis);

};
