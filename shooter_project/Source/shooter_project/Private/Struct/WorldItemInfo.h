// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WorldItemInfo.generated.h"

/**
 * 월드에 표시되는 아이템 정보를 기록하기 위하여 사용되는 구조체입나다.
 */
USTRUCT(BlueprintType)
struct FWorldItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemName;

	// 아이템 Skeletal Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* ItemMesh;

};
