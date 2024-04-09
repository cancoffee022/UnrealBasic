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

	// ������ �߻�ð�
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

	// �Ѿ� �߻�
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// ������ �߻� �ð� ����
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet(FVector direction);
};
