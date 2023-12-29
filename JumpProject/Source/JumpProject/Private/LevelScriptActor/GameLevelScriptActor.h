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
	// ���� ������ ������ ������ ���̺� ����
	class UDataTable* DT_ColorType;

	// ���� �������� ������ �ִ� ��
	TMap<EColorType, FLinearColor> ColorDatas;

	// ������ų ���� �׷� ���� Ŭ�����Դϴ�.
	TSubclassOf<class ALineGroupActor> BP_LineGroupActorClass;

	// ������ ������ ���� ������ �����Ű�� ���� ����
	EColorType NextPassableColor;

public:
	AGameLevelScriptActor();

protected:
	virtual void BeginPlay() override;

private:
	// ���� �׷��� �����մϴ�.
	// lineGroupIndex : ���� �׷� �������� �����մϴ�
	// return : ������ ���� �׷� ��ü�� ��ȯ�մϴ�
	class ALineGroupActor* GenerateLineGroup(int32 lineGroupIndex);

	// ������ ������ ��ȯ�մϴ�
	EColorType GetRandomColorType() const;

	// ���� �׷쿡�� ���� �����ϰ� ���� ���� Ÿ�� �迭�� ��ȯ�մϴ�.
	TArray<EColorType> GetSuffledColorTypeArray(EColorType inclusiveColor);

	// �� ���� ���� ��ü��ŵ�ϴ�.
	void Swap(EColorType& ref_a, EColorType& ref_b);

public:
	// ���� Ÿ�Կ� ���� ������ ��ȯ�մϴ�
	FLinearColor GetColorData(EColorType colorType) const;
};
