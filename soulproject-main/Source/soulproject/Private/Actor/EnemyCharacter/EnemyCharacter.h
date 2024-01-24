// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	// 적 정보 데이터 테이블 에셋
	class UDataTable* EnemyDataTable;

	// 적 데이터
	struct FEnemyData* EnemyData;

protected:
	// 적 코드
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName EnemyCode;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// 컨트롤러가 캐릭터에 빙의되었을 때 호출됩니다 
	virtual void PossessedBy(AController* NewController) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 적 정보를 초기화합니다.
	void InitializeEnemyData();

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
