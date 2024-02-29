#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PlayerCharacterData.generated.h"

/**
 *	플레이어 캐릭터의 기본 정보를 자타내기 위한 구조체
 */
USTRUCT()
struct FPlayerCharacterData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	// 최대체력
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHp;
	
	// 최대 스테미너
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxStamina;

	// 공격력
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Atk;

	// 방어력
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Def;

};
