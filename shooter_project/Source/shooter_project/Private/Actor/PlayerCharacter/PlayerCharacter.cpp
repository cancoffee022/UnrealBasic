#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerCharacterMovementComponent>
	(ACharacter::CharacterMovementComponentName))
	// ACharacter::CharacterMovementComponentName 로
	// 생성된 컴포넌트(기본 CharacterMovementComponent)의 형식으로
	// UPlayerCharacterMovementComponent 로 교체합니다
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY
	(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn'"));

	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}

	static ConstructorHelpers::FClassFinder<UPlayerCharacterAnimInstance> ANIMBP_PLAYERCHARACTER(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_PlayerCharacter.AnimBP_PlayerCharacter_C'"));

	if (ANIMBP_PLAYERCHARACTER.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_PLAYERCHARACTER.Class);
	}

	// 컨트롤러의 Yaw회전을 사용하지 않습니다
	bUseControllerRotationYaw = false;

	// 이동 컴포넌트 교체
	//PawnMovement

	// 스프링암 컴포넌트 추가
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
	SpringArmComponent->SocketOffset = FVector::RightVector * 50.f;

	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritPitch = true;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CAM_COMP"));
	CameraComponent->SetupAttachment(SpringArmComponent);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::OnPlayerCharacterBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void APlayerCharacter::OnPlayerCharacterEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void APlayerCharacter::OnJumpInput()
{
	Jump();
}

void APlayerCharacter::OnHorizontalInput(float axis)
{
	UPlayerCharacterMovementComponent * movementComponent = Cast<UPlayerCharacterMovementComponent>(GetCharacterMovement());

	InputAxisRaw.Y = axis;

	movementComponent->OnHorizontalMovement(axis);
}

void APlayerCharacter::OnVerticalInput(float axis)
{
	UPlayerCharacterMovementComponent* movementComponent = Cast<UPlayerCharacterMovementComponent>(GetCharacterMovement());

	InputAxisRaw.X = axis;

	movementComponent->OnVerticalMovement(axis);
}


