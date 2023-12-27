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
	
	// ���� ������Ʈ ��
	static float GetLineObjectTerm(){ return 400.f; }

	// ���� �׷� ��
	static float GetLineGroupTerm() { return 50.f; }

	// ���� ������Ʈ �̵� �ӷ�
	static float GetLineObjectScrollingSpeed() { return 200.0f; }

	// ���� �׷� �̵� �ӷ�
	static float GetLineGroupMoveSpeed() { return 5.0f; }

	// ���� ������Ʈ ũ��
	static FVector GetLineObjectSize() { return FVector(1.0f, 4.0f, 0.25f); }

};
