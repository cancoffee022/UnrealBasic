#include "Actor/PlayerController/GamePlayerController.h"
#include "../../Actor/GameCharacter/GameCharacter.h"

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// ���� �� �Է� �̺�Ʈ ���ε�
	InputComponent->BindAxis(TEXT("VerticalMove"), this,
		&ThisClass::OnVerticalMovementInput);
	// ���� �� �Է� �̺�Ʈ ���ε�
	InputComponent->BindAxis(TEXT("HorizontalMove"), this,
		&ThisClass::OnHorizontalMovementInput);
}

void AGamePlayerController::OnVerticalMovementInput(float axis)
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	FVector2D inputVector = playerCharacter->GetInputVector();
	inputVector.Y = axis;
	playerCharacter->UpdateInputVector(inputVector);
}

void AGamePlayerController::OnHorizontalMovementInput(float axis)
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	FVector2D inputVector = playerCharacter->GetInputVector();
	inputVector.X = axis;
	playerCharacter->UpdateInputVector(inputVector);
}
