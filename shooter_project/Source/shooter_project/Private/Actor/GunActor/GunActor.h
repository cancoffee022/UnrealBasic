// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

UCLASS()
class AGunActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TSubclassOf<class ABulletActor> BP_BulletActor;


protected:
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* GunMesh;

private:
	struct FWorldItemInfo* GunInfo;

	// 마지막 발사시간
	UPROPERTY()
	float LastFireTime;
	
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
	FORCEINLINE void SetGunInfo(struct FWorldItemInfo* worldItemInfo)
	{
		GunInfo = worldItemInfo;
	}

	// 총알 발사
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// 마지막 발사 시간 갱신
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet(FVector direction);
};
