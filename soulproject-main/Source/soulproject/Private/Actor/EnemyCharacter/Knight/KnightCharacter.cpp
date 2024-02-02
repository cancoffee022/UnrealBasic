#include "Actor/EnemyCharacter/Knight/KnightCharacter.h"
#include "Actor/EnemyController/Knight/KnightController.h"

#include "AnimInstance/KnightCharacter/KnightCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

AKnightCharacter::AKnightCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SK_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/GKnight/Meshes/SK_GothicKnight_VA.SK_GothicKnight_VA'"));

	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	
	static ConstructorHelpers::FClassFinder<UKnightCharacterAnimInstance> ANIMBP_KNIGHT
	(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_KnightCharacter.AnimBP_KnightCharacter_C'"));

	if (ANIMBP_KNIGHT.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_KNIGHT.Class);
	}

	// ��Ʈ�ѷ� ����
	SetEnemyController(AKnightController::StaticClass());

	// �� �ڵ� ����
	EnemyCode = TEXT("000002");

	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}

void AKnightCharacter::Tick(float dt)
{
	Super::Tick(dt);

	// �ִ� �ν��Ͻ� �Ķ���� ����
	UpdateAnimInstanceParams();
}

void AKnightCharacter::UpdateAnimInstanceParams()
{
	UKnightCharacterAnimInstance* animInst =
		Cast<UKnightCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (!IsValid(animInst)) return;

	// �ӷ¼���
	animInst->SetCurrentSpeed(GetVelocity().Length());
}
