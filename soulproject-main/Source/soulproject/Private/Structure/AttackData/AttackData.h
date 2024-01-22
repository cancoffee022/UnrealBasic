#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AttackData.generated.h"

// 공격 정보를 나타내는 구조체 입니다
USTRUCT()
struct FAttackData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 공격 이름
	UPROPERTY(EditAnywhere)
	FName AttackName;

	// 같은 공격을 연계시킬 경우 섹션 이름을 콤보별로 정리합니다
	UPROPERTY(EditAnywhere)
	TArray<FName> LinkableAttackSectionNames;

	// 재생시킬 애님 몽타주 에셋을 나타냅니다
	UPROPERTY(EditAnywhere)
	class UAnimMontage* UseAnimMontage;

	UPROPERTY(EditAnywhere)
	float AttackDamage;

	int32 GetMaxComboCount() const
	{
		return LinkableAttackSectionNames.Num();
	}
};
