// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class AGameLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	// 생성시킬 라인 그룹 액터 클래스입니다.
	TSubclassOf<class ALineGroupActor> BP_LineGroupActorClass;

public:
	AGameLevelScriptActor();

protected:
	UPROPERTY(EditAnywhere)
	int32 InitialLineGroupCount;

protected:
	virtual void BeginPlay() override;

private:
	// 라인 그룹을 생성합니다.
	// lineGroupIndex : 라인 그룹 엔덱스를 전달합니다
	// return : 생성된 라인 그룹 객체를 반환합니다
	class ALineGroupActor* GenerateLineGroup(int32 lineGroupIndex);
};
