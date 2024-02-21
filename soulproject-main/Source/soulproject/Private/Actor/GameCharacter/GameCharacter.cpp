#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/StaticMeshComponent.h"
#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "Component/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"
#include "Component/PlayerCharacterAnimController/PlayerCharacterAnimController.h"
#include "AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"
#include "Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "Component/PlayerCharacterInteractComponent/PlayerCharacterInteractComponent.h"

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

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_HIT(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/GirlKnight1/Animations/AnimMontage_Hit.AnimMontage_Hit'"));

	if (ANIMMONTAGE_HIT.Succeeded())
	{
		HitAnimMontage = ANIMMONTAGE_HIT.Object;
	}

	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ �߰�
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

	InteractComponent =
		CreateDefaultSubobject<UPlayerCharacterInteractComponent>(
			TEXT("PLAYER_INTERACT_COMPONENT"));

	WeaponMesh =
		CreateDefaultSubobject<UStaticMeshComponent>(
			TEXT("WEAPON_MESH"));

	// SpringArm ������Ʈ�� ��Ʈ ������Ʈ�� �߰��մϴ�.
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);

	// ��Ʈ�ѷ� Yaw ȸ�� ��� X
	bUseControllerRotationYaw = false;

	// �����Ʈ �������� ȸ�� ���
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// ȸ�� �ӵ� ����
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 450.0f, 0.0f);

	// ���������� ȸ���� ��Ʈ�ѷ��� ȸ������ ��ġ��ŵ�ϴ�.
	SpringArmComponent->bUsePawnControlRotation = true;

	// ĳ���� SkeletalMesh
	if (SK_CHARACTER_MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHARACTER_MESH.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::DownVector * 88.0f,
			FRotator(0.0f, -90.0f, 0.0f));
	}
	
	// �ִϸ��̼� �������Ʈ ����
	if (ANIMBP_PLAYER_CHARACTER.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_PLAYER_CHARACTER.Class);
	}
	
	// ���� ���̱�
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("Socket_Weapon"));
	if (SM_SABER.Succeeded())
	{
		WeaponMesh->SetStaticMesh(SM_SABER.Object);
		WeaponMesh->SetCollisionProfileName(TEXT("NoCollision"));
	}

	//�÷��̾� ĳ������ ���� �����մϴ�
	SetGenericTeamId(FGenericTeamId(ECharacterTeam::Player));

	// ���� �̺�Ʈ ����
	OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnDamaged);
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	UPlayerCharacterAnimInstance* animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	
	PlayerCharacterAnimController->SetAnimInstance(animInst);
	
	// ���� ���� �Է� Ȯ�� ���� �̺�Ʈ ����
	PlayerCharacterAnimController->onNextAttackInputCheckStarted.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::StartCheckingNextAttackInput);
	
	// ���� ���� �Է� Ȯ�� �� �̺�Ʈ ����
	PlayerCharacterAnimController->onNextAttackInputCheckFinished.BindUObject(
		AttackComponent, &UPlayerCharacterAttackComponent::FinishCheckingNextAttackInput);

	// ���� ���� Ȱ��ȭ/��Ȱ��ȭ �̺�Ʈ ����
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

	// ���� ���� ��ġ ����
	AttackComponent->UpdateWeaponSocketLocation(WeaponMesh);
}

void AGameCharacter::OnDamaged(AActor* damageActor, float damage, const UDamageType* damageType, AController* instigatedBy, AActor* damageCauser)
{
	// �´� �ִϸ��̼� ���
	PlayAnimMontage(HitAnimMontage);
	
	PlayerCharacterMovementComponent->OnHit();

	// ����
	FVector knockBackDirection = (GetActorLocation() - damageCauser->GetActorLocation());
	knockBackDirection.Z = 5.f;
	knockBackDirection.GetSafeNormal();

	// �˹� ��ŵ�ϴ�
	PlayerCharacterMovementComponent->AddImpulse(knockBackDirection, damage* 1.f);
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

void AGameCharacter::OnInteractionInput()
{
	// ��ȣ�ۿ� �õ�
	InteractComponent->TryInteraction();
}
