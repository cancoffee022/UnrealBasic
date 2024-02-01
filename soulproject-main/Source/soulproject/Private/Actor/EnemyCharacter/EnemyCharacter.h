// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UWidgetComponent* WidgetComponent;

private:
	// 적 정보 데이터 테이블 에셋
	class UDataTable* EnemyDataTable;

protected:
	// 적 데이터
	struct FEnemyData* EnemyData;

	// 현재 체력
	UPROPERTY()
	float CurrentHp;

	// 사망 상태
	UPROPERTY()
	bool IsDead;
	
	UPROPERTY()
	float LastDamagedTime;

	// 사망시 사용될 메테리얼
	UPROPERTY()
	class UMaterialInstanceDynamic* MaterialInstanceOnDead;

	FTimerHandle HUDShowTimerHandle;

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

protected: 
	// 적 컨트롤러를 설정합니다.
	virtual void SetEnemyController(TSubclassOf<class AEnemyController> controllerClass,
		EAutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned);
	// 대미지를 입은경우 호출됩니다
	// gameCharacter : GameCharacter 객체가 전달됩니다
	// damage : 가공된 대미지 수치가 전달됩니다.
	virtual void OnDamaged(class AGameCharacter* gameCharacter, float damage);

	// 적이 사망한 경우 호출되는 메서드
	virtual void OnDead();

	// 적이 제거될 때 호출됩니다
	virtual void OnEnemyDestroy();

	// 대미지를 계산합니다.
	// damage : 입은 피해량이 전달됩니다.
	// return : 가공된 대미지 수치를 반환합니다
	virtual float CalculateDamage(float damage);

};
