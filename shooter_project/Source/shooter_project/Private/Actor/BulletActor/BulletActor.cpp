// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/BulletActor/BulletActor.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "../shooter_project.h"

// Sets default values
ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>("DEF_ROOT");
	SetRootComponent(DefaultRootComponent);

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("SM_BULLET");
	BulletMesh->SetupAttachment(GetRootComponent());

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PROJECTILE_MOVEMENT"));

}

void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		timerHandle,
		FTimerDelegate::CreateUObject(this,&ThisClass::DestoryBullet),
		BULLETACTOR_LIFETIME, false);

}

void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletActor::DestoryBullet()
{
	Destroy();
}

