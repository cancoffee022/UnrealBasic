#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterAttackComponent.generated.h"

//아무 공격도 하지 있지 않음을 나타낼 매크로 상수
#define ATTACK_NONE TEXT("NONE")

// 공격1, 공격2 매크로 상수
// TODO 추후 변경해야함
#define COMBO_ATTACK_01 TEXT("Combo_Attack_01")
#define COMBO_ATTACK_02 TEXT("Combo_Attack_02")


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private: // 임시로 사용되는 변수들 추후 제거됨
	class UAnimMontage* ComboAttackMontage;

private:
	// 현재 실행중인 공격을 나타냅니다
	FName CurrentAttackName;

	// 요청된 공격 큐
	TQueue<FName> RequestAttackQueue;

	// 플레이어 캐릭터 객체를 나타냅니다
	class AGameCharacter* PlayerCharacter;

public:	
	UPlayerCharacterAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// 스킬을 순서대로 처리합니다.
	void SkillProcedure();
		
	// 공격을 실행합니다.
	// TODO : 추후 FName 형식을 구조체로 변경
	void StartAttack(FName attackInfo);

public:
	void ClearCurrentAttack();

	// 공격을 요청합니다.
	void RequestAttack(FName attackName);
};
