#pragma once

#include "CoreMinimal.h"
#include "GameTurn.generated.h"

/**
 * 
 */

// 열거 형식을 선언합니다.
// BlueprintType : 블루 프린트에서도 사용 가능하도록 합니다.
// 블루프린트에서 사용할 열거 형식이라면, BlueprintType 작성과 함께
// 언더라잉 타입을 uint8 형식으로 지정해야 합니다.
UENUM(BlueprintType)
enum class EGameTurn : uint8
{
	Turn_Player		UMETA(DisplayName = "플레이어 턴"),
	Trun_AI			UMETA(DisplayName = "AI 턴")
};

// UMETA()
// 클래슨나 인터페이스, 구조체, 열거 타입, 열거 타입요소, 함수, 속성등의
// 동작하는 방식을 제어할때  사용하는 메타데이터 지정자
