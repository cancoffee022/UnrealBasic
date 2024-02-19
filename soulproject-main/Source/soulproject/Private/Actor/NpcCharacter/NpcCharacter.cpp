// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/NpcCharacter/NpcCharacter.h"
#include "Structure/NpcData/NpcData.h"

// Sets default values
ANpcCharacter::ANpcCharacter()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_NPCDATA(
		TEXT(""));

	if (DT_NPCDATA.Succeeded())
	{
		DT_NpcData = DT_NPCDATA.Object;
	}
 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANpcCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeNpcData();
}

void ANpcCharacter::InitializeNpcData()
{
}

// Called every frame
void ANpcCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANpcCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

