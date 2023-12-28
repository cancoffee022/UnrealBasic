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
	// ���� Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EColorType ColorType;

	// ���� ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};
