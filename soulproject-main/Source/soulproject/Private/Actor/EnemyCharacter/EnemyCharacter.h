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
	// �� ���� ������ ���̺� ����
	class UDataTable* EnemyDataTable;

protected:
	// �� ������
	struct FEnemyData* EnemyData;

	// ���� ü��
	UPROPERTY()
	float CurrentHp;

	// ��� ����
	UPROPERTY()
	bool IsDead;
	
	UPROPERTY()
	float LastDamagedTime;

	// ����� ���� ���׸���
	UPROPERTY()
	class UMaterialInstanceDynamic* MaterialInstanceOnDead;

	FTimerHandle HUDShowTimerHandle;

protected:
	// �� �ڵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName EnemyCode;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// ��Ʈ�ѷ��� ĳ���Ϳ� ���ǵǾ��� �� ȣ��˴ϴ� 
	virtual void PossessedBy(AController* NewController) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �� ������ �ʱ�ȭ�մϴ�.
	void InitializeEnemyData();

private:
	UFUNCTION()
	void OnDamaged(
		// ������� ���� ����
		AActor* DamagedActor,
		// ���ط�
		float Damage,
		// ����� ����
		const UDamageType* DamageType,
		// ���ظ� ���� ���� ��Ʈ�ѷ�
		AController* InstigatedBy,
		// ���� ����
		AActor* DamageCauser
	);

protected: 
	// �� ��Ʈ�ѷ��� �����մϴ�.
	virtual void SetEnemyController(TSubclassOf<class AEnemyController> controllerClass,
		EAutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned);
	// ������� ������� ȣ��˴ϴ�
	// gameCharacter : GameCharacter ��ü�� ���޵˴ϴ�
	// damage : ������ ����� ��ġ�� ���޵˴ϴ�.
	virtual void OnDamaged(class AGameCharacter* gameCharacter, float damage);

	// ���� ����� ��� ȣ��Ǵ� �޼���
	virtual void OnDead();

	// ���� ���ŵ� �� ȣ��˴ϴ�
	virtual void OnEnemyDestroy();

	// ������� ����մϴ�.
	// damage : ���� ���ط��� ���޵˴ϴ�.
	// return : ������ ����� ��ġ�� ��ȯ�մϴ�
	virtual float CalculateDamage(float damage);

};
