#pragma once
#include "CoreMinimal.h"

/**
 * 
 */

struct FGameConstants
{

public:
	// ���� ������Ʈ ����
	static const int32 NUMBER_OF_LINEOBJECT = 5;
	
	// ���� ������Ʈ ũ��
	static FVector GetLineObjectSize() { return FVector(1.0f, 4.0f, 0.25f); }

	// ���� ������Ʈ ��
	static float GetLineObjectTerm(){ return 400.f; }
};
