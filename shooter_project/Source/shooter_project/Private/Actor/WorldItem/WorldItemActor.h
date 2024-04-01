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
	// 월드 아이템 정보를 담는 DataTable 에셋
	class UDataTable* DT_WorldItemInfo;

protected:
	// 액터의 루트 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* DefaultRootComponent;

	// 캐릭터와 상호작용 가능 영역을 나타내는 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* InteractableArea;

	// SkeletalMesh 에셋을 표시하기 위한 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* ItemSkeletalMesh;

	// StaticMesh 에셋을 표시하기 위한 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* ItemStaticMesh;

	// 아이템 코드
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemCode;

public:
	AWorldItemActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// 월드 아이템을 초기화합니다.
	void InitializeWorldItem();

};
