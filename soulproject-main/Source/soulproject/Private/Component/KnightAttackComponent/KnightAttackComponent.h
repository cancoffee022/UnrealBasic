// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "KnightAttackComponent.generated.h"

#define SWORD_SOCKET_START TEXT("Socket_Start")
#define SWORD_SOCKET_END TEXT("Socket_End")


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UKnightAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	struct FEnemyData* EnemyData;

	UPROPERTY()
	class UAnimMontage* AttackAnimMontage;

	UPROPERTY()
	class UAnimMontage* ParriedAnimMontage;

	UPROPERTY()
	class UStaticMeshComponent* SwordMeshComponent;

	// ���� ���� Ȱ��ȭ ����
	UPROPERTY()
	bool IsAttackAreaEnabled;

	// ���ظ� ���� ���͸� �ӽ÷� ������ �迭
	TArray<class AActor*> TempDamagedActors;

public:	
	UKnightAttackComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool IsBlocked(class AGameCharacter* gameCharacter, class AActor* ownerEnemy) const;

	// ���� ���� �˻�
	void CheackAttackArea();

public:
	void InitializeAttackComponent(class UStaticMeshComponent* swordMeshComponent,
		struct FEnemyData* enemyData);

	void Attack();

	void OnAttackFinished();

	void EnableAttackArea();
	void DisableAttackArea();

};
