#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterAttackComponent.generated.h"

//�ƹ� ���ݵ� ���� ���� ������ ��Ÿ�� ��ũ�� ���
#define ATTACK_NONE TEXT("NONE")

// ����1, ����2 ��ũ�� ���
// TODO ���� �����ؾ���
#define COMBO_ATTACK_01 TEXT("Combo_Attack_01")
#define COMBO_ATTACK_02 TEXT("Combo_Attack_02")


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private: // �ӽ÷� ���Ǵ� ������ ���� ���ŵ�
	class UAnimMontage* ComboAttackMontage;

private:
	// ���� �������� ������ ��Ÿ���ϴ�
	FName CurrentAttackName;

	// ��û�� ���� ť
	TQueue<FName> RequestAttackQueue;

	// �÷��̾� ĳ���� ��ü�� ��Ÿ���ϴ�
	class AGameCharacter* PlayerCharacter;

public:	
	UPlayerCharacterAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// ��ų�� ������� ó���մϴ�.
	void SkillProcedure();
		
	// ������ �����մϴ�.
	// TODO : ���� FName ������ ����ü�� ����
	void StartAttack(FName attackInfo);

public:
	void ClearCurrentAttack();

	// ������ ��û�մϴ�.
	void RequestAttack(FName attackName);
};
