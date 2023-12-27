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

	// 라인 그룹을 이루는 라인들을 나타내는 StaticMeshComponent
	TArray<class UStaticMeshComponent*> LineObjects;

	// 라인 그룹 인덱스를 나타냅니다
	// 가장 위에 배치된 라인 그룹이 0번으로 사용됩니다.
	// 이 인덱스에 따라 라인 그룹이 배치되는 위치가 결정됩니다.
	int32 LineGroupIndex;
	
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

	// 라인 그룹을 인덱스 값에 따라 이동시킵니다
	// deltaTime : 프레임 사이 간격시간을 전달합니다.
	void MoveLineGroup(float DeltaTime);

	// 라인 오브젝트를 스크롤링 시킵니다
	// deltaTime : 프레임 사이 간격시간을 전달합니다.
	void ScrollingLineObject(float deltaTime);

public:
	// 라인 그룹을 초기화합니다.
	// index : 설정시킬 라인그룹 인덱스를 전달합니다
	void InitializeLineGroup(int32 index);

public:
	// 라인 그룹 인덱스를 설정합니다
	void SetLineGroupIndex(int32 index) 
	{
		LineGroupIndex = index;
	}

};
