// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemyData.generated.h"

/**
 * �� ������ ��Ÿ���� ���� ����ü
 */
USTRUCT()
struct FEnemyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// �� �̸�
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;
	
	// �ִ� ü��
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHP;

	// �ൿ Ʈ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<class UBehaviorTree> BehaviorTreeAsset;
	// FSoftObjetPath : ���� ����, �񵿱� �ε带 ���Ͽ� ��θ� ������ �� �ִ� ����
	// TSoftObjectPtr �� FSoftObjectPath �� Wrapper �����̸�, ���ø��� ���� ������ ���¸� ������ �� �ִ� ����� ����.
	// �� �������� ���� ������ ������ ��� ���ڿ��� �Է��ϴ� ��ſ� ������ �����Ͽ� ��θ� �����Ҽ� �ִ�
	// �̷��� �����س��� ��δ� StreamableManager �� ���� �񵿱������� �ε��ų�� �ֽ��ϴ�


};
