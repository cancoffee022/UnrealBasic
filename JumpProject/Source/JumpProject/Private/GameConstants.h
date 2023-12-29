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
	FORCEINLINE static float GetLineObjectTerm(){ return 400.f; }

	// ���� �׷� ��
	FORCEINLINE static float GetLineGroupTerm() { return 50.f; }

	// ���� ������Ʈ �̵� �ӷ�
	FORCEINLINE static float GetLineObjectScrollingSpeed() { return 200.0f; }

	// ���� �׷� �̵� �ӷ�
	FORCEINLINE static float GetLineGroupMoveSpeed() { return 5.0f; }

	// ���� ������Ʈ ũ��
	FORCEINLINE static FVector GetLineObjectSize() { return FVector(1.0f, 4.0f, 0.25f); }

	// �÷��̾� ��ü�� ������
	FORCEINLINE static float GetPlayerSphereRadius() { return 10.f; }

};
