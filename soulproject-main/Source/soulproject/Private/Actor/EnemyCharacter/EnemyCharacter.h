// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void OnDamaged(
		// 대미지를 입은 액터
		AActor* DamagedActor,
		// 피해량
		float Damage,
		// 대미지 종류
		const UDamageType* DamageType,
		// 피해를 입힌 가해 컨트롤러
		AController* InstigatedBy,
		// 가해 액터
		AActor* DamageCauser
	);

};
