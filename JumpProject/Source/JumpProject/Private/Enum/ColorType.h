#pragma once

#include "CoreMinimal.h"
#include "ColorType.generated.h"

// �������Ʈ������ ��� ������ ���� ������ ���� ��Ģ�� ���Ѿ� �մϴ�.
// - ������ ����Ÿ�� ���(enum class)
// - UENUM(BlueprintType) ���
// - .generated.h ����
// - underling type �� uint8 �������� ����
// - ���ĸ� �տ� E �ۼ�

UENUM(BlueprintType)
enum class EColorType : uint8
{
	Color_Red		= 0 UMETA(DisplayName = "Red"),
	Color_Yellow	= 1 UMETA(DisplayName = "Yellow"),
	Color_Sky		= 2 UMETA(DisplayName = "Sky"),
	Color_Magenta	= 3 UMETA(DisplayName = "Magenta"),
	Color_White		= 4 UMETA(DisplayName = "White"),
	Color_Orange	= 5 UMETA(DisplayName = "Orange"),
	Color_Green		= 6 UMETA(DisplayName = "Green"),
};
