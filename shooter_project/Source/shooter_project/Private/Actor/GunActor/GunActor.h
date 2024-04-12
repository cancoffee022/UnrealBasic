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
	// �Ѿ� Ŭ����
	UPROPERTY()
	TSubclassOf<class ABulletActor> BP_BulletActor;

	UPROPERTY()
	TSubclassOf<class AActor> FireBlockDecalActorClass;

	UPROPERTY()
	class AActor* FireBlockDecalActor;


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

	// ������ �߻�ð�
	UPROPERTY()
	float LastFireTime;

	UPROPERTY()
	bool IsBlocked;

	UPROPERTY()
	FVector BlockedNormal;

	UPROPERTY()
	FVector BlockedLocation;
	
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

	// �߻� ������ ��ȯ�մϴ�.
	// cameraWorldLocation : ī�޶��� ���� ��ġ�� �����մϴ�
	// return : ������ ��ȯ�մϴ�
	void UpdateFireDirection(
		const FVector& cameraWorldLocation,
		const FVector& direction);

	// �Ѿ� �߻�
	UFUNCTION(BlueprintImplementableEvent)
	void Fire();

	// ������ �߻� �ð� ����
	UFUNCTION(BlueprintCallable)
	void UpdateLastFireTime();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFirable();

	// �Ѿ��� �����մϴ�
	UFUNCTION(BlueprintCallable)
	class ABulletActor* CreateBullet();
	
	// �Ѿ� �ӷ��� ����ϴ�
	UFUNCTION(BlueprintCallable)
	float GetBulletSpeed() const;

	FORCEINLINE void SetOwnerCharacter(class APlayerCharacter* ownerCharacter)
	{
		OwnerCharacter = ownerCharacter;
	}

};
