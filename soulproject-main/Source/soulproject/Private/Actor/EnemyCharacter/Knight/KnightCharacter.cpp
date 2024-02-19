#include "Actor/EnemyCharacter/Knight/KnightCharacter.h"
#include "Actor/EnemyController/Knight/KnightController.h"

#include "Component/KnightAttackComponent/KnightAttackComponent.h"

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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SWORD(
		TEXT("/Script/Engine.StaticMesh'/Game/Resources/EnemyCharacter/GKnight/Meshes/Weapon/SM_WP_GothicKnight_Sword.SM_WP_GothicKnight_Sword'"));
	
	if (SM_SWORD.Succeeded())
	{
		SwordMesh = SM_SWORD.Object;
	}

	static ConstructorHelpers::FClassFinder<UKnightCharacterAnimInstance> ANIMBP_KNIGHT
	(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_KnightCharacter.AnimBP_KnightCharacter_C'"));

	if (ANIMBP_KNIGHT.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_KNIGHT.Class);
	}

	// 공격 컴포넌트 설정
	AttackComponent = CreateDefaultSubobject<UKnightAttackComponent>(TEXT("KNIGHT_ATTACK_COMP"));

	// 칼 스태틱 메시 컴포넌트 생성
	SwordMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SWORD_SMCOMP"));

	// 컨트롤러 설정
	SetEnemyController(AKnightController::StaticClass());

	// 적 코드 설정
	EnemyCode = TEXT("000002");

	GetCharacterMovement()->MaxWalkSpeed = 300.f;

	// 컴포넌트 계층구조 설정
	SwordMeshComponent->SetupAttachment(GetMesh(), TEXT("Socket_Weapon"));

	// 칼 Mesh 설정
	SwordMeshComponent->SetStaticMesh(SwordMesh);
	SwordMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
}

void AKnightCharacter::BeginPlay()
{
	Super::BeginPlay();

	AttackComponent->InitializeAttackComponent(SwordMeshComponent, EnemyData);
}

void AKnightCharacter::Tick(float dt)
{
	Super::Tick(dt);

	// 애님 인스턴스 파라미터 갱신
	UpdateAnimInstanceParams();
}

void AKnightCharacter::UpdateAnimInstanceParams()
{
	UKnightCharacterAnimInstance* animInst =
		Cast<UKnightCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (!IsValid(animInst)) return;

	// 속력설정
	animInst->SetCurrentSpeed(GetVelocity().Length());
}
