#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Actor/WorldItem/WorldItemActor.h"
#include "Actor/PlayerController/GamePlayerController.h"
#include "Actor/BulletActor/BulletActor.h"

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

	static ConstructorHelpers::FClassFinder<ABulletActor> BP_BULLETACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/BP_BulletActor.BP_BulletActor_C'"));
	if (BP_BULLETACTOR.Succeeded())
	{
		BP_BulletActor = BP_BULLETACTOR.Class;
	}

	// 컨트롤러의 Yaw회전을 사용하지 않습니다
	bUseControllerRotationYaw = false;

	// 스프링암 컴포넌트 추가
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeLocation(FVector(0.f, 0.f, 50.f));
	SpringArmComponent->SocketOffset = FVector::RightVector * 50.f;

	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritPitch = true;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = true;

	// 카메라 컴포넌트 추가
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

	if (IsFireStarted)
	{
		Fire();
	}
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
	// 겹친 액터가 TAG_WORLDITEM 태그를 갖는 경우
	if (OtherActor->ActorHasTag(TAG_WORLDITEM))
	{
		// 배열에 겹친 WorldItem 추가
		AddOverlappedWorldItem(Cast<AWorldItemActor>(OtherActor));

		// 상호작용 위젯 표시
		ShowNearestWorldItemInteractionWidget();
	}
}

void APlayerCharacter::OnPlayerCharacterEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// 겹친 액터가 TAG_WORLDITEM 태그를 갖는 경우
	if (OtherActor->ActorHasTag(TAG_WORLDITEM))
	{
		// 배열에 겹침이 끝난 WorldItem 제거
		RemoveOverlappedWorldItem(Cast<AWorldItemActor>(OtherActor));

		// 상호작용 위젯 표시
		ShowNearestWorldItemInteractionWidget();
	}
}

void APlayerCharacter::AddOverlappedWorldItem(AWorldItemActor* worldItem)
{
	// 이미 추가된 아이템일 경우 리턴
	if (OverlappedWorldItems.Contains(worldItem)) return;

	// 배열에 추가
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
	// 자신의 플레이어 컨트롤러를 얻습니다
	AGamePlayerController* playerController =
		Cast<AGamePlayerController>(GetController());

	if (!IsLocallyControlled()) return;
	if (!IsValid(playerController)) return;

	// 플레이어 위젯 객체를 얻습니다
	UPlayerWidget* playerWidget = playerController->GetPlayerWidget();

	// 플레이어 위젯이 유효하지 않은 경우 함수 호출 종료
	if (!IsValid(playerWidget)) return;

	if (OverlappedWorldItems.Num() < 1)
	{
		// 위젯 숨기기
		playerWidget->HideInteractionWidget();
		return;
	}

	// 가장 가까운 아이템을 
	AWorldItemActor* nearestWorldItemActor = OverlappedWorldItems[0];

	// 아이템 정보를 얻스비낟
	FWorldItemInfo* nearestWorldItemInfo = nearestWorldItemActor->GetWorldItemInfo();

	if (nearestWorldItemInfo == nullptr)
	{
		playerWidget->HideInteractionWidget();
		return;
	}

	FText nearestWorldItemName = nearestWorldItemInfo->ItemName;
	
	// 위젯을 표시합니다
	playerWidget->ShowInteractionItem(nearestWorldItemName);

}

void APlayerCharacter::EquipItem(FWorldItemInfo* worldItemInfo)
{
	// 무기 Mesh를 초기화 합니다
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

	IsEquipped = true;
	EquippedItemType = worldItemInfo->ItemType;

	targetSkeletalMeshComponent->SetSkeletalMesh(worldItemInfo->ItemMesh);

}

void APlayerCharacter::Fire()
{
	USkeletalMeshComponent* targetSKMeshComponent = nullptr;

	switch (EquippedItemType)
	{
	case EWorldItemType::Weapon_Pistol:
		targetSKMeshComponent = PistolMesh;
		break;
	case EWorldItemType::Weapon_Rifle:
		targetSKMeshComponent = RifleMesh;
		break;
	case EWorldItemType::Weapon_Shotgun:
		targetSKMeshComponent = ShotgunMesh;
		break;
	}
	if (targetSKMeshComponent == nullptr) return;
	// 발사 위치를 얻습니다
	//FVector firePos = targetSKMeshComponent->GetSocketLocation(SOCKET_NAME_FIRE_POS);


	FTransform spawnTransform = targetSKMeshComponent->GetSocketTransform(SOCKET_NAME_FIRE_POS);
	GetWorld()->SpawnActor<ABulletActor>(BP_BulletActor, spawnTransform);
}


void APlayerCharacter::OnFirePressed()
{
	if (!IsEquipped) return;

	IsFireStarted = true;
}

void APlayerCharacter::OnFireReleased()
{
	IsFireStarted = false;
}

void APlayerCharacter::OnGetItemPressed()
{
	// 주울 아이템이 없다면 함수 호출 종료
	if (OverlappedWorldItems.Num() == 0) return;

	// 아이템 액터
	AWorldItemActor* worldItemActor = OverlappedWorldItems[0];

	// 아이템 정보
	FWorldItemInfo* worldItemInfo = worldItemActor->GetWorldItemInfo();

	// 무기 아이템일 경우
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



