// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GameCharacter/GameCharacter.h"

#include "../../Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ �߰�
	PlayerCharacterMovementComponent = 
		CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
			TEXT("MOVEMENT_COMPONENT"));
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameCharacter::UpdateInputVector(FVector2D inputVector)
{
	InputVector = inputVector;

	PlayerCharacterMovementComponent->OnMovementInput(InputVector);
}

