// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "../Enum/ColorType.h"
#include "GameLevelScriptActor.generated.h"


/**
 * 
 */
UCLASS()
class AGameLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int32 InitialLineGroupCount;

private:
	// 색상 정보를 가지는 데이터 테이블 에셋
	class UDataTable* DT_ColorType;

	// 색상 정보들을 가지고 있는 맵
	TMap<EColorType, FLinearColor> ColorDatas;

	// 생성시킬 라인 그룹 액터 클래스입니다.
	TSubclassOf<class ALineGroupActor> BP_LineGroupActorClass;

	// 생성된 라인의 정답 색상을 저장시키기 위한 변수
	EColorType NextPassableColor;

public:
	AGameLevelScriptActor();

protected:
	virtual void BeginPlay() override;

private:
	// 라인 그룹을 생성합니다.
	// lineGroupIndex : 라인 그룹 엔덱스를 전달합니다
	// return : 생성된 라인 그룹 객체를 반환합니다
	class ALineGroupActor* GenerateLineGroup(int32 lineGroupIndex);

	// 랜덤한 색상을 반환합니다
	EColorType GetRandomColorType() const;

	// 라인 그룹에서 사용될 랜덤하게 섞인 색상 타입 배열을 반환합니다.
	TArray<EColorType> GetSuffledColorTypeArray(EColorType inclusiveColor);

	// 두 색상 값을 교체시킵니다.
	void Swap(EColorType& ref_a, EColorType& ref_b);

public:
	// 색상 타입에 따라 색상값을 반환합니다
	FLinearColor GetColorData(EColorType colorType) const;
};
