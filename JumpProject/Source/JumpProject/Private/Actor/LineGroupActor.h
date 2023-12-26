// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LineGroupActor.generated.h"

UCLASS()
class ALineGroupActor : public AActor
{
	GENERATED_BODY()

protected:
	// 컴포넌트 계층 구조를 정리하기 위해 사용되는 빈 씬 컴포넌트입니다.
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* LineGroupRootComponent;

	TArray<class UStaticMeshComponent*> LineObjects;
	
public:	
	// Sets default values for this actor's properties
	ALineGroupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 라인 오브젝트를 생성합니다
	void InitializeLineObjects(
		class UStaticMesh* lineObjectStaticMesh,
		class UMaterial* lineObjectMaterial);

};
