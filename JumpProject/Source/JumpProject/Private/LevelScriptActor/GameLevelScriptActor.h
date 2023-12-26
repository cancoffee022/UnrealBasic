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
	// ������ų ���� �׷� ���� Ŭ�����Դϴ�.
	TSubclassOf<class ALineGroupActor> BP_LineGroupActorClass;

public:
	AGameLevelScriptActor();

protected:
	UPROPERTY(EditAnywhere)
	int32 InitialLineGroupCount;

protected:
	virtual void BeginPlay() override;

private:
	// ���� �׷��� �����մϴ�.
	// lineGroupIndex : ���� �׷� �������� �����մϴ�
	// return : ������ ���� �׷� ��ü�� ��ȯ�մϴ�
	class ALineGroupActor* GenerateLineGroup(int32 lineGroupIndex);
};
