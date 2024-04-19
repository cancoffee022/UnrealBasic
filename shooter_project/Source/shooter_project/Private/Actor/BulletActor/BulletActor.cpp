// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/BulletActor/BulletActor.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "../shooter_project.h"

// Sets default values
ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>("DEF_ROOT");
	SetRootComponent(DefaultRootComponent);

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("SM_BULLET");
	BulletMesh->SetupAttachment(GetRootComponent());

	BulletCollision = CreateDefaultSubobject<USphereComponent>(TEXT("BULLET_COLLSION"));
	BulletCollision->SetupAttachment(GetRootComponent());

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PROJECTILE_MOVEMENT"));
	ProjectileMovement->bSweepCollision = true;
}

void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		FTimerDelegate::CreateUObject(this,&ThisClass::DestroyBullet),
		BULLETACTOR_LIFETIME, false);

	BulletMesh->SetCollisionProfileName(TEXT("NoCollision"));

	BulletCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnBulletOverllap);

}

void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletActor::InitializeBullet(float damage)
{
	BulletDamage = damage;
}

void ABulletActor::DestroyBullet()
{
	Destroy();
}

void ABulletActor::OnBulletOverllap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	bool isHitCharacterMesh = false;
	bool isHitMesh = false;
	WLOG(TEXT("OTHER"));
	// ¸öÀ» ¸ÂÃá °æ¿ì
	if (Cast<USkeletalMeshComponent>(OtherComp))
	{
		UGameplayStatics::ApplyDamage(OtherActor,
			BulletDamage,
			nullptr, this, UDamageType::StaticClass());
		isHitCharacterMesh = true;
	}
	// ¸Ó¸®¸¦ ¸ÂÃá °æ¿ì
	else if (Cast<USphereComponent>(OtherComp) && OtherComp->ComponentHasTag(TEXT("Head")))
	{
		UGameplayStatics::ApplyDamage(OtherActor,
			BulletDamage * 10.0f,
			nullptr, this, UDamageType::StaticClass());
		isHitCharacterMesh = true;
	}
	else if (Cast<UStaticMeshComponent>(OtherComp))
	{
		WLOG(TEXT("OTHER"));
		isHitMesh = true;
	}

	if (isHitCharacterMesh || isHitMesh)
	{
		if (TimerHandle.IsValid())
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		DestroyBullet();
	}


}

