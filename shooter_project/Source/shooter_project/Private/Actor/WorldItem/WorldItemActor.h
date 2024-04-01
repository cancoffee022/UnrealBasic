// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldItemActor.generated.h"

UCLASS()
class AWorldItemActor : public AActor
{
	GENERATED_BODY()

private:
	// ���� ������ ������ ��� DataTable ����
	class UDataTable* DT_WorldItemInfo;

protected:
	// ������ ��Ʈ ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* DefaultRootComponent;

	// ĳ���Ϳ� ��ȣ�ۿ� ���� ������ ��Ÿ���� ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* InteractableArea;

	// SkeletalMesh ������ ǥ���ϱ� ���� ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* ItemSkeletalMesh;

	// StaticMesh ������ ǥ���ϱ� ���� ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ItemStaticMesh;

	// ������ �ڵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemCode;

public:
	AWorldItemActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// ���� �������� �ʱ�ȭ�մϴ�.
	void InitializeWorldItem();

};
