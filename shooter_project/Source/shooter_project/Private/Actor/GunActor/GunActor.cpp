// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GunActor/GunActor.h"
#include "Actor/BulletActor/BulletActor.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"

#include "Components/DecalComponent.h"
#include "Components/AudioComponent.h"

#include "Sound/SoundBase.h"

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

	static ConstructorHelpers::FClassFinder<AActor> BP_AUDIOACTOR(
		TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_AudioActor.BP_AudioActor_C'"));
	if (BP_AUDIOACTOR.Succeeded()) BP_AudioActor = BP_AUDIOACTOR.Class;

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

	FString fireSoundKey = TEXT("FireSound");
	if (GunInfo->Sounds.Contains(fireSoundKey))
	{
		FireSound = GunInfo->Sounds[fireSoundKey];
	}

	FString damage = TEXT("Damage");
	if (GunInfo->FloatValues.Contains(damage))
	{
		Damage = GunInfo->FloatValues[damage];
	}

	MaxBullets = GetMaxBulletCount();

	OnReloaded();
}

UAudioComponent* AGunActor::GetUseableAudioComponent()
{ 
	UAudioComponent* audioComponent = nullptr;

	for (UAudioComponent* audioComp : SoundPool)
	{
		// 사용중이지 않은 오디오 컴포넌트를 찾은 경우
		if (!audioComp->IsPlaying())
		{
			audioComponent = audioComp;
			UE_LOG(LogTemp, Warning, TEXT("AGunActor::GetUseableAudioComponent() AudioActor Recycle"));
			break;
		}
	}

	if (audioComponent == nullptr)
	{
		AActor* createdAudioActor = GetWorld()->SpawnActor<AActor>(BP_AudioActor, GetActorLocation(), FRotator::ZeroRotator);

		UE_LOG(LogTemp, Warning, TEXT("AGunActor::GetUseableAudioComponent() AuidoActor Created!"))

		TArray<UAudioComponent*> audioComponents;
		createdAudioActor->GetComponents<UAudioComponent>(audioComponents);

		audioComponent = audioComponents[0];
		SoundPool.Add(audioComponent);

		// 발사 사운드 설정
		audioComponent->SetSound(FireSound);
	}
	return audioComponent;
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
	FinishReload();
}

void AGunActor::UpdateLastFireTime()
{
	LastFireTime = GetWorld()->GetTimeSeconds();

	OnFireFinished.Broadcast(RemainBullets, MaxBullets);
}

bool AGunActor::IsFirable()
{
	if (GunInfo == nullptr) return false;

	// 총알이 남아있지 않은 경우 발사 X
	if (RemainBullets <= 0) return false;

	float currentTime = GetWorld()->GetTimeSeconds();
	return currentTime > LastFireTime + GunInfo->ShotDelay;
}

AActor* AGunActor::CreateSound()
{
	UAudioComponent* audioComponent = GetUseableAudioComponent();
	// 위치 설정
	audioComponent->GetOwner()->SetActorLocation(GetActorLocation());
	
	audioComponent->Play();

	return audioComponent->GetOwner();
}

ABulletActor* AGunActor::CreateBullet()
{
	if (!IsValid(GunMesh)) return nullptr;

	ABulletActor* bulletActor = GetWorld()->SpawnActor<ABulletActor>(BP_BulletActor,
		GunMesh->GetSocketLocation(SOCKET_NAME_FIRE_POS),
		FRotator::ZeroRotator);

	bulletActor->InitializeBullet(Damage);

	return bulletActor;
}

bool AGunActor::IsReloadable() const
{
	return RemainBullets != MaxBullets;
}

void AGunActor::StartReload()
{
	bIsReloading = true;
}

void AGunActor::FinishReload()
{
	bIsReloading = false;
}

bool AGunActor::IsReloading()
{
	return bIsReloading;
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


