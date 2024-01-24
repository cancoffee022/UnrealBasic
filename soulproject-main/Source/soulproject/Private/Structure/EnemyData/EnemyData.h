// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemyData.generated.h"

/**
 * 적 정보를 나타내기 위한 구조체
 */
USTRUCT()
struct FEnemyData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 적 이름
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;
	
	// 최대 체력
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHP;

	// 행동 트리 에셋
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<class UBehaviorTree> BehaviorTreeAsset;
	// FSoftObjetPath : 에셋 동기, 비동기 로드를 위하여 경로를 저장할 수 있는 형식
	// TSoftObjectPtr 는 FSoftObjectPath 의 Wrapper 형식이며, 템플릿을 통해 에셋의 형태를 지정할 수 있는 기능을 제공.
	// 이 두형식을 통해 에디터 내에서 경로 문자열을 입력하는 대신에 에셋을 선택하여 경로를 선택할수 있다
	// 이렇게 지정해놓은 경로는 StreamableManager 를 통해 비동기적으로 로드시킬수 있습니다


};
