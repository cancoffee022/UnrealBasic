// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "Actor/EnemyController/EnemyController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AIControllerClass = AEnemyController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;


	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnDamaged);

}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::OnDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage = %.2f"), Damage);
}


