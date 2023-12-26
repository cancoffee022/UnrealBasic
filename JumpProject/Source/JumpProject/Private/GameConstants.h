#pragma once
#include "CoreMinimal.h"

/**
 * 
 */

struct FGameConstants
{

public:
	// 라인 오브젝트 개수
	static const int32 NUMBER_OF_LINEOBJECT = 5;
	
	// 라인 오브젝트 크기
	static FVector GetLineObjectSize() { return FVector(1.0f, 4.0f, 0.25f); }

	// 라인 오브젝트 텀
	static float GetLineObjectTerm(){ return 400.f; }
};
