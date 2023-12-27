// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelScriptActor/GameLevelScriptActor.h"
#include "Actor/LineGroupActor.h"

AGameLevelScriptActor::AGameLevelScriptActor()
{
	static ConstructorHelpers::FClassFinder<ALineGroupActor> BP_LINEGROUPACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_LineGroupActor.BP_LineGroupActor_C'"));

	if (BP_LINEGROUPACTOR.Succeeded())
		BP_LineGroupActorClass = BP_LINEGROUPACTOR.Class;
}

void AGameLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < InitialLineGroupCount; ++i)
	{
		GenerateLineGroup(i);
	}
}

ALineGroupActor* AGameLevelScriptActor::GenerateLineGroup(int32 lineGroupIndex)
{
	// LineGroupActor�� �����մϴ�
	ALineGroupActor* newLineGroup = 
		GetWorld()->SpawnActor<ALineGroupActor>(BP_LineGroupActorClass);

	// ������ LineGroupActor�� �ʱ�ȭ �մϴ�.
	newLineGroup->InitializeLineGroup(lineGroupIndex);

	return newLineGroup;
}
