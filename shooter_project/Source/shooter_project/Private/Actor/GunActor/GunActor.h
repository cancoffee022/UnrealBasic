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
	// 사운드 클래스
	UPROPERTY()
	TSubclassOf<class AActor> BP_AudioActor;

	// 사운드 풀
	UPROPERTY()
	TArray<class UAudioComponent*> SoundPool;

	// 총알 클래스
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

	// 마지막 발사시간
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

	// 발사 방향을 반환합니다.
	// cameraWorldLocation : 카메라의 월드 위치를 전달합니다
	// return : 방향을 반환합니다
	void UpdateFireDirection(
		const FVector& cameraWorldLocation,
		const FVector& direction);

	// 재장전이 끝났을때 호출되는 함수
	void OnReloaded();

	// 총알 발사
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// 마지막 발사 시간 갱신
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	// 발사 가능함을 확인합니다
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	UFUNCTION(BlueprintCallable)
	class AActor* CreateSound();

	// 총알을 생성합니다
	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet();

	// 재장전 가능 상태를 확인합니다.
	bool IsReloadable() const;

	void StartReload();
	void FinishReload();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsReloading();
	
	// 총알 속력을 얻습니다
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
