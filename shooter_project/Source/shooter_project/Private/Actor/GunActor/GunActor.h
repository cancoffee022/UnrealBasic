// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

DECLARE_EVENT_TwoParams(AGunActor, FOnFireFinishedEvent, int32, int32)

UCLASS()
class AGunActor : public AActor
{
	GENERATED_BODY()

public:
	FOnFireFinishedEvent OnFireFinished;

private:
	// ���� Ŭ����
	UPROPERTY()
	TSubclassOf<class AActor> BP_AudioActor;

	// ���� Ǯ
	UPROPERTY()
	TArray<class UAudioComponent*> SoundPool;

	// �Ѿ� Ŭ����
	UPROPERTY()
	TSubclassOf<class ABulletActor> BP_BulletActor;

	UPROPERTY()
	TSubclassOf<class AActor> FireBlockDecalActorClass;

	UPROPERTY()
	class AActor* FireBlockDecalActor;

	UPROPERTY()
	class UDecalComponent* FireBlockDecalComponent;


protected:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* DefaultRootComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(BlueprintReadOnly)
	FVector FireDirection;

	UPROPERTY(VisibleAnywhere)
	class APlayerCharacter* OwnerCharacter;
	

private:
	struct FWorldItemInfo* GunInfo;

	UPROPERTY()
	class USoundBase* FireSound;

	// ������ �߻�ð�
	UPROPERTY()
	float LastFireTime;

	UPROPERTY()
	bool IsBlocked;
	
	UPROPERTY()
	bool bIsReloading;

	UPROPERTY()
	FVector BlockedNormal;

	UPROPERTY()
	FVector BlockedLocation;
	
	UPROPERTY()
	int32 MaxBullets;

	UPROPERTY()
	int32 RemainBullets;

public:	
	// Sets default values for this actor's properties
	AGunActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void InitializeGunActor(struct FWorldItemInfo* worldItemInfo);

private:
	class UAudioComponent* GetUseableAudioComponent();

public:
	UFUNCTION(BlueprintCallable)
	void DecreaseRemainBullet();

	// �߻� ������ ��ȯ�մϴ�.
	// cameraWorldLocation : ī�޶��� ���� ��ġ�� �����մϴ�
	// return : ������ ��ȯ�մϴ�
	void UpdateFireDirection(
		const FVector& cameraWorldLocation,
		const FVector& direction);

	// �������� �������� ȣ��Ǵ� �Լ�
	void OnReloaded();

	// �Ѿ� �߻�
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// ������ �߻� �ð� ����
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	// �߻� �������� Ȯ���մϴ�
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	UFUNCTION(BlueprintCallable)
	class AActor* CreateSound();

	// �Ѿ��� �����մϴ�
	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet();

	// ������ ���� ���¸� Ȯ���մϴ�.
	bool IsReloadable() const;

	void StartReload();
	void FinishReload();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsReloading();
	
	// �Ѿ� �ӷ��� ����ϴ�
	UFUNCTION(BlueprintCallable)
	float GetBulletSpeed() const;

	int32 GetMaxBulletCount() const;

	FORCEINLINE void SetOwnerCharacter(class APlayerCharacter* ownerCharacter)
	{
		OwnerCharacter = ownerCharacter;
	}

	FORCEINLINE int32 GetMaxBullets() const
	{
		return MaxBullets;
	}
	
	FORCEINLINE int32 GetRemainBullets() const
	{
		return RemainBullets;
	}

};
