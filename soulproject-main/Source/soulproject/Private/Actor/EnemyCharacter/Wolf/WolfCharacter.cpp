// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyCharacter/Wolf/WolfCharacter.h"
#include "Actor/EnemyController/Wolf/WolfController.h"

#include "AnimInstance/WolfCharacter/WolfCharacterAnimInstance.h"

#include "Component/WolfAttackComponent/WolfAttackComponent.h"

AWolfCharacter::AWolfCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/AnimalVarietyPack/Wolf/Meshes/SK_Wolf.SK_Wolf'"));

	static ConstructorHelpers::FClassFinder<UWolfCharacterAnimInstance> ANIMBP_WOLF(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_WolfCharacter.AnimBP_WolfCharacter_C'"));

	// ���� ������Ʈ �߰�
	AttackComponent = CreateDefaultSubobject<UWolfAttackComponent>(TEXT("ATTACK_COMP"));

	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}

	if (ANIMBP_WOLF.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_WOLF.Class);
	}

	// �� �ڵ� ����
	EnemyCode = TEXT("000003");

	// ��Ʈ�ѷ� ����
	SetEnemyController(AWolfController::StaticClass());

}

void AWolfCharacter::Tick(float dt)
{
	Super::Tick(dt);

	UpdateAnimInstanceParams();
}

void AWolfCharacter::UpdateAnimInstanceParams()
{
	UWolfCharacterAnimInstance* animInst = Cast<UWolfCharacterAnimInstance>(GetMesh()->GetAnimInstance());

	if (!IsValid(animInst)) return;

	// �ӷ� ����
	animInst->SetCurrentSpeed(GetVelocity().Length());
}
