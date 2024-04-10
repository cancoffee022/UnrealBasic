// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GunActor/GunActor.h"
#include "Actor/BulletActor/BulletActor.h"

#include "Struct/WorldItemInfo.h"

#include "../shooter_project.h"

// Sets default values
AGunActor::AGunActor()
{

	static ConstructorHelpers::FClassFinder<ABulletActor> BP_BULLETACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Actor/BP_BulletActor.BP_BulletActor_C'"));
	if (BP_BULLETACTOR.Succeeded())
	{
		BP_BulletActor = BP_BULLETACTOR.Class;
	}
	PrimaryActorTick.bCanEverTick = true;

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
	
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunActor::UpdateFireDirection(const FVector& cameraWorldLocation) const
{
	//FHitResult hitResult;
	//
	//GetWorld()->LineTraceSingleByProfile(hitResult,)


	//FireDirection = 

}

void AGunActor::UpdateLastFireTime()
{
	LastFireTime = GetWorld()->GetTimeSeconds();
}

bool AGunActor::IsFirable()
{
	if (GunInfo == nullptr) return false;

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
	else if (GunInfo->FloatValues.Contains(bulletSpeedKey)) return 0;

	float speed = GunInfo->FloatValues[bulletSpeedKey];

	return speed;
}


