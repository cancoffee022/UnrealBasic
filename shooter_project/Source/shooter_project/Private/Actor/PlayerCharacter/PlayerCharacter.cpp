#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Actor/WorldItem/WorldItemActor.h"
#include "Actor/PlayerController/GamePlayerController.h"
#include "Actor/BulletActor/BulletActor.h"
#include "Actor/GunActor/GunActor.h"

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
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_RELOAD(
		TEXT("/Script/Engine.AnimMontage'/Game/JetpackAnimSet/Animations/Standard/AnimMontage_Reload.AnimMontage_Reload'"));
	if (ANIMMONTAGE_RELOAD.Succeeded()) AnimMontage_Reload = ANIMMONTAGE_RELOAD.Object;

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

	Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance())->OnReloadedEvent.AddUObject(this, &ThisClass::OnReloaded);

	bReplicates = true;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentSpeed = GetVelocity().Length();

	AGamePlayerController* playerController = Cast<AGamePlayerController>(GetController());
	if (!IsLocallyControlled()) return;
	

	CameraPitchAngle = playerController->GetControlRotation().Pitch;

	if (IsFireStarted)
	{
		Fire();
	}

	if (IsEquipped())
	{
		EquippedGunActor->UpdateFireDirection(
			CameraComponent->GetComponentLocation(),
			Cast<AActor>(playerController)->GetActorForwardVector());
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
	FTransform socketTransform = FTransform();

	if (IsEquipped())
	{
		EquippedGunActor->Destroy();
		EquippedGunActor = nullptr;
	}

	EquippedGunActor = GetWorld()->SpawnActor<AGunActor>(worldItemInfo->GunActorClass, socketTransform);
	EquippedGunActor->InitializeGunActor(worldItemInfo);
	EquippedGunActor->SetOwnerCharacter(this);

	FName socketName;
	switch (worldItemInfo->ItemType)
	{
	case EWorldItemType::Weapon_Pistol:
		socketName = TEXT("Socket_Pistol");
		break;
	case EWorldItemType::Weapon_Rifle:
		socketName = TEXT("Socket_Rifle");
		break;
	case EWorldItemType::Weapon_Shotgun:
		socketName = TEXT("Socket_Shotgun");
		break;

	}

	// 생성된 총 액터를 캐릭터 Mesh에 붙입니다
	EquippedGunActor->AttachToComponent(GetMesh(),
		FAttachmentTransformRules::KeepWorldTransform, socketName);
	EquippedGunActor->SetActorRelativeLocation(FVector::ZeroVector);
	EquippedGunActor->SetActorRelativeRotation(FVector::RightVector.Rotation());

	EquippedGunActor->OnFireFinished.AddUObject(this, &ThisClass::OnFireFinished);
	OnFireFinished(EquippedGunActor->GetMaxBulletCount(), EquippedGunActor->GetMaxBulletCount());

	EquippedItemType = worldItemInfo->ItemType;

}

void APlayerCharacter::OnFireFinished(int32 remain, int32 max)
{
	// 자신의 플레이어 컨트롤러를 얻습니다
	AGamePlayerController* playerController =
		Cast<AGamePlayerController>(GetController());

	if (!IsLocallyControlled()) return;
	if (!IsValid(playerController)) return;

	playerController->GetPlayerWidget()->UpdateBulletRemainText(remain, max);
	UE_LOG(LogTemp, Warning, TEXT("remain-%d max-%d"), remain, max);
}

void APlayerCharacter::Fire()
{
	if (!IsValid(EquippedGunActor)) return;

	EquippedGunActor->Fire();
}

void APlayerCharacter::OnReloaded()
{
	if (!IsValid(EquippedGunActor)) return;

	EquippedGunActor->OnReloaded();
	
	// 자신의 플레이어 컨트롤러를 얻습니다
	AGamePlayerController* playerController =
		Cast<AGamePlayerController>(GetController());

	if (!IsLocallyControlled()) return;
	if (!IsValid(playerController)) return;
	
	playerController->GetPlayerWidget()->UpdateBulletRemainText(EquippedGunActor->GetRemainBullets(),
		EquippedGunActor->GetMaxBulletCount());

	UE_LOG(LogTemp, Warning, TEXT("APlayerCharacter::OnReloaded"));
}


void APlayerCharacter::OnFirePressed()
{
	if (!IsEquipped()) return;

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

void APlayerCharacter::OnReloadPressed()
{
	if (!IsValid(EquippedGunActor)) return;
	if (!EquippedGunActor->IsReloadable()) return;
	if (EquippedGunActor->IsReloading()) return;
	EquippedGunActor->StartReload();

	FName montageSection = FName();

	switch (EquippedItemType)
	{
	case EWorldItemType::Weapon_Pistol:
		montageSection = MONTAGESECTION_PISTOL_RELOAD;
		break;
		
	case EWorldItemType::Weapon_Rifle:
		montageSection = MONTAGESECTION_RIFLE_RELOAD;
		break;
		
	case EWorldItemType::Weapon_Shotgun:
		montageSection = MONTAGESECTION_SHOTGUN_RELOAD;
		break;
	}

	PlayAnimMontage(AnimMontage_Reload, 1.0f, montageSection);

}

bool APlayerCharacter::IsEquipped() const
{
	return IsValid(EquippedGunActor);
}



