// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerController/GamePlayerController.h"

#include "Actor/PlayerCharacter/PlayerCharacter.h"

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("Horizontal"), this, &ThisClass::OnHorizontalInput);
	InputComponent->BindAxis(TEXT("Vertical"), this, &ThisClass::OnVerticalInput);

	InputComponent->BindAxis(TEXT("MouseX"), this, &ThisClass::OnMouseX);
	InputComponent->BindAxis(TEXT("MouseY"), this, &ThisClass::OnMouseY);
}

void AGamePlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
}

void AGamePlayerController::OnGetItemPressed()
{
}

void AGamePlayerController::OnGetItemReleased()
{
}

void AGamePlayerController::OnFirePressed()
{
}

void AGamePlayerController::OnFireReleased()
{
}

void AGamePlayerController::OnZoomPressed()
{
}

void AGamePlayerController::OnZoomReleased()
{
}

void AGamePlayerController::OnVerticalInput(float axis)
{
	APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (!IsValid(playerCharacter)) return;

	playerCharacter->OnVerticalInput(axis);
}

void AGamePlayerController::OnHorizontalInput(float axis)
{
	APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (!IsValid(playerCharacter)) return;

	playerCharacter->OnHorizontalInput(axis);
}

void AGamePlayerController::OnMouseX(float axis)
{
	AddYawInput(axis);
}

void AGamePlayerController::OnMouseY(float axis)
{
	AddPitchInput(axis);
}
