#pragma once

#include "CoreMinimal.h"
#include "GameTurn.generated.h"

/**
 * 
 */

// ���� ������ �����մϴ�.
// BlueprintType : ��� ����Ʈ������ ��� �����ϵ��� �մϴ�.
// �������Ʈ���� ����� ���� �����̶��, BlueprintType �ۼ��� �Բ�
// ������� Ÿ���� uint8 �������� �����ؾ� �մϴ�.
UENUM(BlueprintType)
enum class EGameTurn : uint8
{
	Turn_Player		UMETA(DisplayName = "�÷��̾� ��"),
	Trun_AI			UMETA(DisplayName = "AI ��")
};

// UMETA()
// Ŭ������ �������̽�, ����ü, ���� Ÿ��, ���� Ÿ�Կ��, �Լ�, �Ӽ�����
// �����ϴ� ����� �����Ҷ�  ����ϴ� ��Ÿ������ ������
