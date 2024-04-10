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
	class USceneComponent* DefaultRootComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* GunMesh;

	UPROPERTY(VisibleAnywhere)
	FVector FireDirection;

	UPROPERTY(VisibleAnywhere)
	class APlayerCharacter* OwnerCharacter;
	

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

	// 발사 방향을 반환합니다.
	// cameraWorldLocation : 카메라의 월드 위치를 전달합니다
	// return : 방향을 반환합니다
	void UpdateFireDirection(const FVector& cameraWorldLocation) const;

	// 총알 발사
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// 마지막 발사 시간 갱신
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	// 총알을 생성합니다
	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet();
	
	// 총알 속력을 얻습니다
	UFUNCTION(BlueprintCallable)
	float GetBulletSpeed() const;

	FORCEINLINE void SetOwnerCharacter(class APlayerCharacter* ownerCharacter)
	{
		OwnerCharacter = ownerCharacter;
	}

};
