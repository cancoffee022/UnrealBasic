#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Actor/WorldItem/WorldItemActor.h"
#include "Actor/PlayerController/GamePlayerController.h"

#include "AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Widget/PlayerWidget/PlayerWidget.h"

#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "Struct/WorldItemInfo.h"

#include "../shooter_project.h"
#include "Net/UnrealNetwork.h"


// Sets default values
APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerCharacterMovementComponent>
	(ACharacter::CharacterMovementComponentName))
	// ACharacter::CharacterMovementComponentName ��
	// ������ ������Ʈ(�⺻ CharacterMovementComponent)�� ��������
	// UPlayerCharacterMovementComponent �� ��ü�մϴ�
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

	// ��Ʈ�ѷ��� Yawȸ���� ������� �ʽ��ϴ�
	bUseControllerRotationYaw = false;

	// �������� ������Ʈ �߰�
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
	SpringArmComponent->SocketOffset = FVector::RightVector * 50.f;

	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritPitch = true;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = true;

	// ī�޶� ������Ʈ �߰�
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CAM_COMP"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	PistolMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_PISTON"));
	PistolMesh->SetupAttachment(GetMesh(), TEXT("Socket_Pistol"));
	
	RifleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_RIFLE"));
	RifleMesh->SetupAttachment(GetMesh(), TEXT("Socket_Rifle"));
	
	ShotgunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_SHOTGUN"));
	ShotgunMesh->SetupAttachment(GetMesh(), TEXT("Socket_Shotgun"));

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ThisClass, CurrentSpeed);
	DOREPLIFETIME(ThisClass, InputAxisRaw);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnPlayerCharacterBeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddUniqueDynamic(this, &APlayerCharacter::OnPlayerCharacterEndOverlap);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentSpeed = GetVelocity().Length();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::OnPlayerCharacterBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ��ģ ���Ͱ� TAG_WORLDITEM �±׸� ���� ���
	if (OtherActor->ActorHasTag(TAG_WORLDITEM))
	{
		// �迭�� ��ģ WorldItem �߰�
		AddOverlappedWorldItem(Cast<AWorldItemActor>(OtherActor));

		// ��ȣ�ۿ� ���� ǥ��
		ShowNearestWorldItemInteractionWidget();
	}
}

void APlayerCharacter::OnPlayerCharacterEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// ��ģ ���Ͱ� TAG_WORLDITEM �±׸� ���� ���
	if (OtherActor->ActorHasTag(TAG_WORLDITEM))
	{
		// �迭�� ��ħ�� ���� WorldItem ����
		RemoveOverlappedWorldItem(Cast<AWorldItemActor>(OtherActor));

		// ��ȣ�ۿ� ���� ǥ��
		ShowNearestWorldItemInteractionWidget();
	}
}

void APlayerCharacter::AddOverlappedWorldItem(AWorldItemActor* worldItem)
{
	// �̹� �߰��� �������� ��� ����
	if (OverlappedWorldItems.Contains(worldItem)) return;

	// �迭�� �߰�
	OverlappedWorldItems.Add(worldItem);

	SortWorldItemByDistance();
}

void APlayerCharacter::RemoveOverlappedWorldItem(AWorldItemActor* worldItem)
{
	if (!OverlappedWorldItems.Contains(worldItem)) return;

	OverlappedWorldItems.Remove(worldItem);

	SortWorldItemByDistance();
}

void APlayerCharacter::SortWorldItemByDistance()
{
	FVector characterLocation = GetActorLocation();

	OverlappedWorldItems.Sort(
		[characterLocation](AWorldItemActor& a, AWorldItemActor& b)
		{
			FVector aLocation = a.GetActorLocation();
			float aDistance = FVector::Distance(characterLocation, aLocation);

			FVector bLocation = b.GetActorLocation();
			float bDistance = FVector::Distance(characterLocation, bLocation);
			
			return aDistance < bDistance;
		});
}

void APlayerCharacter::ShowNearestWorldItemInteractionWidget()
{
	// �ڽ��� �÷��̾� ��Ʈ�ѷ��� ����ϴ�
	AGamePlayerController* playerController =
		Cast<AGamePlayerController>(GetController());

	if (!IsLocallyControlled()) return;
	if (!IsValid(playerController)) return;

	// �÷��̾� ���� ��ü�� ����ϴ�
	UPlayerWidget* playerWidget = playerController->GetPlayerWidget();

	// �÷��̾� ������ ��ȿ���� ���� ��� �Լ� ȣ�� ����
	if (!IsValid(playerWidget)) return;

	if (OverlappedWorldItems.Num() < 1)
	{
		// ���� �����
		playerWidget->HideInteractionWidget();
		return;
	}

	// ���� ����� �������� 
	AWorldItemActor* nearestWorldItemActor = OverlappedWorldItems[0];

	// ������ ������ �򽺺�
	FWorldItemInfo* nearestWorldItemInfo = nearestWorldItemActor->GetWorldItemInfo();

	if (nearestWorldItemInfo == nullptr)
	{
		playerWidget->HideInteractionWidget();
		return;
	}

	FText nearestWorldItemName = nearestWorldItemInfo->ItemName;
	
	// ������ ǥ���մϴ�
	playerWidget->ShowInteractionItem(nearestWorldItemName);

}

void APlayerCharacter::EquipItem(FWorldItemInfo* worldItemInfo)
{
	// ���� Mesh�� �ʱ�ȭ �մϴ�
	PistolMesh->SetSkeletalMesh(nullptr);
	RifleMesh->SetSkeletalMesh(nullptr);
	ShotgunMesh->SetSkeletalMesh(nullptr);

	USkeletalMeshComponent* targetSkeletalMeshComponent = nullptr;

	switch (worldItemInfo->ItemType)
	{
	case EWorldItemType::Weapon_Pistol:
		targetSkeletalMeshComponent = PistolMesh;
		break;
	case EWorldItemType::Weapon_Rifle:
		targetSkeletalMeshComponent = RifleMesh;
		break;
	case EWorldItemType::Weapon_Shotgun:
		targetSkeletalMeshComponent = ShotgunMesh;
		break;
	}

	if (targetSkeletalMeshComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Target Skeletal Mesh is nullptr"));
		return;
	}
	targetSkeletalMeshComponent->SetSkeletalMesh(worldItemInfo->ItemMesh);

}

void APlayerCharacter::OnGetItemPressed()
{
	// �ֿ� �������� ���ٸ� �Լ� ȣ�� ����
	if (OverlappedWorldItems.Num() == 0) return;

	// ������ ����
	AWorldItemActor* worldItemActor = OverlappedWorldItems[0];

	// ������ ����
	FWorldItemInfo* worldItemInfo = worldItemActor->GetWorldItemInfo();

	// ���� �������� ���
	bool isWeapon = EWorldItemType::RANGE_WEAPON_START < worldItemInfo->ItemType &&
		worldItemInfo->ItemType < EWorldItemType::RANGE_WEAPON_END;

	if (isWeapon) EquipItem(worldItemInfo);

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



