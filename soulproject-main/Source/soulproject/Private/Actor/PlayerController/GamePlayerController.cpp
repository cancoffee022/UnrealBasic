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

	InputComponent->BindAxis(TEXT("MouseX"), this,
		&ThisClass::OnMouseXInput);

	InputComponent->BindAxis(TEXT("MouseY"), this,
		&ThisClass::OnMouseYInput);
}

void AGamePlayerController::OnVerticalMovementInput(float axis)
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnVerticalInput(axis);
}

void AGamePlayerController::OnHorizontalMovementInput(float axis)
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnHorizontalInput(axis);
}

void AGamePlayerController::OnMouseXInput(float axis)
{
	// ��Ʈ�ѷ� Yaw ȸ������ axis ���� ���մϴ�.
	AddYawInput(axis);
}

void AGamePlayerController::OnMouseYInput(float axis)
{
	// ��Ʈ�ѷ� Pitch ȸ������ axis ���� ���մϴ�.
	AddPitchInput(-axis);
}
