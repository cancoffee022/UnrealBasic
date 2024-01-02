// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Enum/ColorType.h"
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

private:
	// 통과 가능한 라인 오브젝트 인덱스를 나타냅니다.
	int32 PassableLineObjectIndex;

	// 캐릭터를 통과시킬 색상 타입
	EColorType PassableColorType;

	// 통과했을 경우 캐릭터에게 설정시킬 색상 타입
	EColorType NextColorType;

	// 통과했을 경우 캐릭터에게 설정시킬 색상
	FLinearColor NextColor;
	
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
	// lineObjectStaticMesh : 라인 오브젝트에 사용될 StaticMesh 에셋을 전달합니다
	// lineObjectMaterial : 라인 오브젝트에 사용될 Material 에셋을 전달합니다.
	void InitializeLineObjects(
		class UStaticMesh* lineObjectStaticMesh,
		class UMaterial* lineObjectMaterial);

	// 라인 오브젝트 색상을 설정합니다
	// colors : 사용 가능한 색상들을 전달합니다.
	// colorTypes : 사용될 색상 타입들을 순서대로 전달합니다.
	void SetLineObjectColors(TArray<FLinearColor> colors, TArray<EColorType> colorTypes);


	// 라인 그룹을 인덱스 값에 따라 이동시킵니다
	// deltaTime : 프레임 사이 간격시간을 전달합니다.
	void MoveLineGroup(float DeltaTime);

	// 라인 오브젝트를 스크롤링 시킵니다
	// deltaTime : 프레임 사이 간격시간을 전달합니다.
	void ScrollingLineObject(float deltaTime);

public:
	// 라인 그룹을 초기화 합니다
	// index : 설정시킨 라인 그룹 인덱스를 전달함
	// colors : 사용 가능한 색상들을 전달합니다.
	// colorTypes : 사용될 색상 타입들을 순서대로 전달합니다.
	// lineObjectStaticMesh : 라인 오브젝트에 사용될 StaticMesh 에셋을 전달합니다
	// lineObjectMaterial : 라인 오브젝트에 사용될 Material 에셋을 전달합니다.
	void InitializeLineGroup(
		int32 index,
		TArray<FLinearColor> colors,
		TArray<EColorType> colorTypes,
		EColorType passableColor,
		EColorType nextColor);

	// 지정한 StaticMeshComponent 가 통과 가능한 LineObject인지 확인합니다.
	// lineObject : 통과 가능 여부를 확인할 StaticMeshComponent를 전달합니다.
	bool IsPassableLineObject(class UStaticMeshComponent* lineObject);

	// 해당 라인 그룹이 통과 되었을 경우 호출됩니다
	// out_NextColor : 출력용 매개변수이며, 플레이어에게 설정ㅇ시킬 다음 색상을 반환합니다.
	void OnLineGroupPassed(FLinearColor& out_NextColor);

public:
	// 라인 그룹 인덱스를 설정합니다
	FORCEINLINE void SetLineGroupIndex(int32 index) 
	{
		LineGroupIndex = index;
	}

	// 다음색상을 반환합니다
	FORCEINLINE FLinearColor GetNextColor() const
	{
		return NextColor;
	}

};
