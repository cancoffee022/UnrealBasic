// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Enum/WorldItemType.h"
#include "WorldItemInfo.generated.h"

/**
 * ���忡 ǥ�õǴ� ������ ������ ����ϱ� ���Ͽ� ���Ǵ� ����ü�Գ���.
 */
USTRUCT(BlueprintType)
struct FWorldItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// ������ �̸�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemName;

	// ������ Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWorldItemType ItemType;
	
	// �߻� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ShotDelay;

	// ������ Skeletal Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* ItemMesh;

	// ������ ���� Ŭ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AGunActor> GunActorClass;

};
