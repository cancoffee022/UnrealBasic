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

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_GUN"));
	SetRootComponent(GunMesh);

	GunInfo = nullptr;

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

ABulletActor* AGunActor::CreateBullet(FVector direction)
{
	if (!IsValid(GunMesh)) return nullptr;

	ABulletActor* bulletActor = GetWorld()->SpawnActor<ABulletActor>(BP_BulletActor,
		GunMesh->GetSocketLocation(SOCKET_NAME_FIRE_POS),
		GetActorRotation());

	bulletActor->SetActorRotation(direction.Rotation());

	return bulletActor;
}


