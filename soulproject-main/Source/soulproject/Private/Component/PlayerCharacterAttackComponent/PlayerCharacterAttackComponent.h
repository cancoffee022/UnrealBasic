#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterAttackComponent.generated.h"

//�ƹ� ���ݵ� ���� ���� ������ ��Ÿ�� ��ũ�� ���
#define ATTACK_NONE				TEXT("NONE")

// �⺻ ������ ��Ÿ���� Ű����
#define DEFAULT_ATTACK_KEYWORD	TEXT("DefaultAttack")

#define WEAPON_SOCKET_START		TEXT("Socket_SaberStart")
#define WEAPON_SOCKET_END		TEXT("Socket_SaberEnd")

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// ���� ������ ���̺��� ��Ÿ���ϴ�
	class UDataTable* DT_Attackdata;
	
	// �ٷ� ������ ���� ��Ų ���� ������ ��Ÿ���ϴ�
	struct FAttackData* PrevAttackData;

	// ���� �������� ������ ��Ÿ���ϴ�
	struct FAttackData* CurrentAttackData;

	// ���� ������ ������ ��� ���� ������
	float ApplyDamage;

	// ���� ���� Ȱ��ȭ ���¸� ��Ÿ���ϴ�.
	bool IsAttackAreaEnabled;

	// ���� �� ������ �� ��ü�� ��� �����ص� �迭
	TArray<class AEnemyCharacter*> AttackDectectedEnemies;

	// �Էµ� �޺� ī��Ʈ
	int32 TargetCombo;

	// ������� ����� �޺� ī��Ʈ�� ��Ÿ���ϴ�.
	int32 CurrentCombo;

	// ���� ���� �Է��� Ȯ���ϰ� ������ ��Ÿ���ϴ�
	bool bCheckingNextAttackInput;

	// ��û�� ���� ť
	TQueue<struct FAttackData*> RequestAttackQueue;

	// �÷��̾� ĳ���� ��ü�� ��Ÿ���ϴ�
	class AGameCharacter* PlayerCharacter;

	// ���� ���������� ��Ÿ���ϴ�.
	bool _IsAttacking;

	// ���� ��ġ�� ���Ǿ����� ��Ÿ���ϴ�
	bool _IsCalculatedPrevSaberSocketLocation;
	
	// ������ ���� ��ġ�� ��Ÿ���ϴ�
	FVector _CurrentSaberStartSocketLocation;
	FVector _CurrentSaberEndSocketLocation;


public:	
	UPlayerCharacterAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// ��ų�� ������� ó���մϴ�.
	void AttackProcedure();

	void CheckAttackArea();

	// ���� ������ ����ϴ�.
	//struct FAttackData* GetAttackData(FName attackName);

public:
	// ���� ���� ��ġ�� �����մϴ�
	// weaponMesh : ���� ��ġ�� ���� StaticMesh ������ �����Ϻ�ϴ�
	void UpdateWeaponSocketLocation(class UStaticMeshComponent* weaponMesh);

	void ClearCurrentAttack();

	// ������ ��û�մϴ�.
	void RequestAttack(FName attackName);

	// ���� ���� �Է� Ȯ�� ����
	void StartCheckingNextAttackInput();
	// ���� ���� �Է� Ȯ�� ��
	void FinishCheckingNextAttackInput();

	// ���� ���� Ȱ��ȭ
	void EnableAttackArea();
	
	// ���� ���� ��Ȱ��ȭ
	void DisableAttackArea();
};