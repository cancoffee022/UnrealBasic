#include "Actor/GameCharacter/GameCharacter.h"

#include "../../Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Component/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AGameCharacter::AGameCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CHARACTER_MESH(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/GirlKnight1/Mesh/SK_GirlKnight1.SK_GirlKnight1'"));

	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ �߰�
	SpringArmComponent = CreateDefaultSubobject<UZoomableSpringArmComponent>(
		TEXT("SPRING_ARM"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	PlayerCharacterMovementComponent =
		CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
			TEXT("MOVEMENT_COMPONENT"));



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


	if (SK_CHARACTER_MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHARACTER_MESH.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::DownVector * 88.0f,
			FRotator(0.0f, -90.0f, 0.0f));
	}
	

}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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