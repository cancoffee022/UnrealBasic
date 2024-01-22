#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterAttackComponent.generated.h"

//아무 공격도 하지 있지 않음을 나타낼 매크로 상수
#define ATTACK_NONE				TEXT("NONE")

// 기본 공격을 나타내는 키워드
#define DEFAULT_ATTACK_KEYWORD	TEXT("DefaultAttack")

#define WEAPON_SOCKET_START		TEXT("Socket_SaberStart")
#define WEAPON_SOCKET_END		TEXT("Socket_SaberEnd")

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// 공격 데이터 테이블을 나타냅니다
	class UDataTable* DT_Attackdata;
	
	// 바로 이전에 실행 시킨 공격 정보를 나타냅니다
	struct FAttackData* PrevAttackData;

	// 현재 실행중인 공격을 나타냅니다
	struct FAttackData* CurrentAttackData;

	// 현재 공격이 적중한 경우 가할 데미지
	float ApplyDamage;

	// 입력된 콤보 카운트
	int32 TargetCombo;

	// 현재까지 진행된 콤보 카운트를 나타냅니다.
	int32 CurrentCombo;

	// 다음 공격 입력을 확인하고 있음을 나타냅니다
	bool bCheckingNextAttackInput;

	// 요청된 공격 큐
	TQueue<struct FAttackData*> RequestAttackQueue;

	// 플레이어 캐릭터 객체를 나타냅니다
	class AGameCharacter* PlayerCharacter;

	// 현재 공격중임을 나타냅니다.
	bool _IsAttacking;

	// 이전 위치가 계산되었음을 나타냅니다
	bool _IsCalculatedPrevSaberSocketLocation;
	
	// 무기의 현재 위치를 나타냅니다
	FVector _CurrentSaberStartSocketLocation;
	FVector _CurrentSaberEndSocketLocation;


public:	
	UPlayerCharacterAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// 스킬을 순서대로 처리합니다.
	void AttackProcedure();

	void CheckAttackArea();

	// 공격 정보를 얻습니다.
	//struct FAttackData* GetAttackData(FName attackName);

public:
	// 무기 소켓 위치를 갱신합니다
	// weaponMesh : 소켓 위치를 얻을 StaticMesh 에셋을 전달하비니다
	void UpdateWeaponSocketLocation(class UStaticMeshComponent* weaponMesh);

	void ClearCurrentAttack();

	// 공격을 요청합니다.
	void RequestAttack(FName attackName);

	// 다음 공격 입력 확인 시작
	void StartCheckingNextAttackInput();
	// 다음 공격 입력 확인 끝
	void FinishCheckingNextAttackInput();
};
