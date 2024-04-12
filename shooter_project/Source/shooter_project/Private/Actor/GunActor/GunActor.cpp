// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GunActor/GunActor.h"
#include "Actor/BulletActor/BulletActor.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"


#include "Components/DecalComponent.h"

#include "Struct/WorldItemInfo.h"

#include "../shooter_project.h"

// Sets default values
AGunActor::AGunActor()
{

	static ConstructorHelpers::FClassFinder<ABulletActor> BP_BULLETACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/BP_BulletActor.BP_BulletActor_C'"));
	if (BP_BULLETACTOR.Succeeded())	BP_BulletActor = BP_BULLETACTOR.Class;
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AActor> BP_FIREBLOCKDECALACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/BP_FireBlockDecal.BP_FireBlockDecal_C'"));
	if (BP_FIREBLOCKDECALACTOR.Succeeded()) FireBlockDecalActorClass = BP_FIREBLOCKDECALACTOR.Class;

	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DEF_ROOT"));
	SetRootComponent(DefaultRootComponent);

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_GUN"));
	GunMesh->SetupAttachment(DefaultRootComponent);
	GunMesh->SetRelativeRotation((FVector::RightVector * -1).Rotation());


	GunInfo = nullptr;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();
	
	FireBlockDecalActor = GetWorld()->SpawnActor<AActor>(FireBlockDecalActorClass);
	TArray<UDecalComponent*> decalComponents;
	FireBlockDecalActor->GetComponents<UDecalComponent>(decalComponents);
	FireBlockDecalComponent = decalComponents[0];

	FireBlockDecalComponent->SetVisibility(false);

	
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FireBlockDecalComponent->SetVisibility(IsBlocked);
	if (IsBlocked)
	{
		FireBlockDecalActor->SetActorLocationAndRotation(
			BlockedLocation,
			BlockedNormal.Rotation());
	}

}

void AGunActor::InitializeGunActor(FWorldItemInfo* worldItemInfo)
{
	GunInfo = worldItemInfo;

	MaxBullets = GetMaxBulletCount();

	OnReloaded();
}

void AGunActor::DecreaseRemainBullet()
{
	if (RemainBullets <= 0) return;

	RemainBullets -= 1;
}

void AGunActor::UpdateFireDirection(const FVector& cameraWorldLocation, const FVector& direction)
{
	FHitResult cameraHitResult;

	FVector start = cameraWorldLocation;
	FVector end = start + (direction * 100000);

	bool isHit = GetWorld()->LineTraceSingleByProfile(
		cameraHitResult, start, end, TEXT("BlockAllDynamic"));

	FVector hitLocation = isHit ? cameraHitResult.Location : end;
	if (cameraHitResult.GetActor() == OwnerCharacter)
	{
		hitLocation = end;
	}

	start = GunMesh->GetSocketLocation(SOCKET_NAME_FIRE_POS);
	end = hitLocation;

	FHitResult gunHitResult;
	isHit = GetWorld()->LineTraceSingleByProfile(
		gunHitResult, start, end, TEXT("BlockAllDynamic"));

	FireDirection = (end - start).GetSafeNormal();

	IsBlocked = false;
	if (isHit)
	{
		BlockedNormal = gunHitResult.Normal;
		BlockedLocation = gunHitResult.Location;
		IsBlocked = (FVector::Distance(hitLocation, gunHitResult.Location) > 1);
	}

}

void AGunActor::OnReloaded()
{
	RemainBullets = MaxBullets;
}

void AGunActor::UpdateLastFireTime()
{
	LastFireTime = GetWorld()->GetTimeSeconds();

	OnFireFinished.Broadcast(RemainBullets, MaxBullets);
}

bool AGunActor::IsFirable()
{
	if (GunInfo == nullptr) return false;
	if (RemainBullets <= 0) return false;

	float currentTime = GetWorld()->GetTimeSeconds();
	return currentTime > LastFireTime + GunInfo->ShotDelay;
}

ABulletActor* AGunActor::CreateBullet()
{
	if (!IsValid(GunMesh)) return nullptr;

	ABulletActor* bulletActor = GetWorld()->SpawnActor<ABulletActor>(BP_BulletActor,
		GunMesh->GetSocketLocation(SOCKET_NAME_FIRE_POS),
		FRotator::ZeroRotator);

	return bulletActor;
}

float AGunActor::GetBulletSpeed() const
{
	FString bulletSpeedKey = TEXT("BulletSpeed");

	if (GunInfo == nullptr) return 0;
	else if (GunInfo->FloatValues.Num() == 0) return 0;
	else if (!GunInfo->FloatValues.Contains(bulletSpeedKey)) return 0;

	float speed = GunInfo->FloatValues[bulletSpeedKey];

	return speed;
}

int32 AGunActor::GetMaxBulletCount() const
{
	FString maxBulletCountKey = TEXT("Bullets");

	if (GunInfo == nullptr) return 0;
	else if (GunInfo->IntValues.Num() == 0) return 0;
	else if (!GunInfo->IntValues.Contains(maxBulletCountKey)) return 0;

	return GunInfo->IntValues[maxBulletCountKey];
}


