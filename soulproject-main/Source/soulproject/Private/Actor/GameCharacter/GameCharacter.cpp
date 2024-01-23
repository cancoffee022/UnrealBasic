#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/StaticMeshComponent.h"
#include "../../Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Component/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"
#include "../../Component/PlayerCharacterAnimController/PlayerCharacterAnimController.h"
#include "../../AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"
#include "../../Component//PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AGameCharacter::AGameCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CHARACTER_MESH(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/GirlKnight1/Mesh/SK_GirlKnight1.SK_GirlKnight1'"));

	static ConstructorHelpers::FClassFinder<UPlayerCharacterAnimInstance> ANIMBP_PLAYER_CHARACTER(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_PlayerCharacter.AnimBP_PlayerCharacter_C'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SABER(
		TEXT("/Script/Engine.StaticMesh'/Game/Resources/GirlKnight1/Mesh/Weapon/SM_Saber.SM_Saber'"));

	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 추가
	SpringArmComponent = CreateDefaultSubobject<UZoomableSpringArmComponent>(
		TEXT("SPRING_ARM"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	PlayerCharacterMovementComponent =
		CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
			TEXT("MOVEMENT_COMPONENT"));

	PlayerCharacterAnimController =
		CreateDefaultSubobject<UPlayerCharacterAnimController>(
			TEXT("PLAYER_CHARACTER_ANIM_CONTROLLER"));

	AttackComponent =
		CreateDefaultSubobject<UPlayerCharacterAttackComponent>(
			TEXT("PLAYER_CHARACTER_ATTACK_COMPONENT"));

	WeaponMesh =
		CreateDefaultSubobject<UStaticMeshComponent>(
			TEXT("WEAPON_MESH"));

	// SpringArm 컴포넌트를 루트 컴포넌트에 추가합니다.
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);

	// 컨트롤러 Yaw 회전 사용 X
	bUseControllerRotationYaw = false;

	// 무브먼트 방향으로 회전 사용
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 회전 속도 설정
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.0f, 0.0f);

	// 스프링암의 회전을 컨트롤러의 회전으로 일치시킵니다.
	SpringArmComponent->bUsePawnControlRotation = true;

	// 캐릭터 SkeletalMesh
	if (SK_CHARACTER_MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHARACTER_MESH.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::DownVector * 88.0f,
			FRotator(0.0f, -90.0f, 0.0f));
	}
	
	// 애니메이션 블루프린트 설정
	if (ANIMBP_PLAYER_CHARACTER.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_PLAYER_CHARACTER.Class);
	}
	
	// 무기 붙이기
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("Socket_Weapon"));
	if (SM_SABER.Succeeded())
	{
		WeaponMesh->SetStaticMesh(SM_SABER.Object);
		WeaponMesh->SetCollisionProfileName(TEXT("NoCollision"));
	}
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	UPlayerCharacterAnimInstance* animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	
	PlayerCharacterAnimController->SetAnimInstance(animInst);
	
	// 다음 공격 입력 확인 시작 이벤트 설정
	PlayerCharacterAnimController->onNextAttackInputCheckStarted.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::StartCheckingNextAttackInput);
	
	// 다음 공격 입력 확인 끝 이벤트 설정
	PlayerCharacterAnimController->onNextAttackInputCheckFinished.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::FinishCheckingNextAttackInput);

	// 공격 영역 활성화/비활성화 이벤트 설정
	PlayerCharacterAnimController->onAttackAreaEnable.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::EnableAttackArea);
	PlayerCharacterAnimController->onAttackAreaDisable.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::DisableAttackArea);


	PlayerCharacterAnimController->onAllowMovementInput.BindUObject(
		PlayerCharacterMovementComponent, &UPlayerCharacterMovementComponent::SetAllowMovementInput);
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 무기 소켓 위치 갱신
	AttackComponent->UpdateWeaponSocketLocation(WeaponMesh);
}

// Called to bind functionality to input
void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameCharacter::OnHorizontalInput(float axis)
{
	PlayerCharacterMovementComponent->HorizontalMove(axis);
}

void AGameCharacter::OnVerticalInput(float axis)
{
	PlayerCharacterMovementComponent->VerticalMove(axis);
}

void AGameCharacter::OnZoomInput(float axis)
{
	SpringArmComponent->ZoomCamera(axis);
}

void AGameCharacter::OnJumpInput()
{
	PlayerCharacterMovementComponent->OnJump();
}

void AGameCharacter::OnAttackInput()
{
	AttackComponent->RequestAttack(DEFAULT_ATTACK_KEYWORD);
}
