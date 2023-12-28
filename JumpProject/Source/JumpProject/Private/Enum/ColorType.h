#pragma once

#include "CoreMinimal.h"
#include "ColorType.generated.h"

// 블루프린트에서도 사용 가능한 열거 형식은 다음 규칙을 지켜야 합니다.
// - 엄격한 열거타입 사용(enum class)
// - UENUM(BlueprintType) 명시
// - .generated.h 포함
// - underling type 을 uint8 형식으로 지정
// - 형식명 앞에 E 작성

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
