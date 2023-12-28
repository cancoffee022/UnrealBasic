#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "../Enum/ColorType.h"
#include "ColorData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FColorData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 색상 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColorType ColorType;

	// 색상 값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};
