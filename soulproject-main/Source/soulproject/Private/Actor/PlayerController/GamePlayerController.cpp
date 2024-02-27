#include "Actor/PlayerController/GamePlayerController.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "Widget/GameWidget/GameWidget.h"

AGamePlayerController::AGamePlayerController()
{
	static ConstructorHelpers::FClassFinder<UGameWidget> WIDGETBP_GAME(
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/GameWidget/WidgetBP_Game.WidgetBP_Game_C'"));

	if (WIDGETBP_GAME.Succeeded())
	{
		GameWidgetClass = WIDGETBP_GAME.Class;
	}
}

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

	InputComponent->BindAxis(TEXT("MouseWheel"), this,
		&ThisClass::OnZoomInput);
	
	InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,
		this, &ThisClass::OnJumpInput);
	
	InputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed,
		this, &ThisClass::OnAttackInput);

	InputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed,
		this, &ThisClass::OnInteractionInput);

}

void AGamePlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	// GameWidget ����
	GameWidget = CreateWidget<UGameWidget>(this, GameWidgetClass);

	// ������ ������ ȭ�鿡 ǥ���մϴ�
	GameWidget->AddToViewport();
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

void AGamePlayerController::OnZoomInput(float axis)
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnZoomInput(axis);
}

void AGamePlayerController::OnJumpInput()
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnJumpInput();

}

void AGamePlayerController::OnAttackInput()
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnAttackInput();
}

void AGamePlayerController::OnInteractionInput()
{
	AGameCharacter* playerCharacter = Cast<AGameCharacter>(GetPawn());
	playerCharacter->OnInteractionInput();
}

UGameWidget* AGamePlayerController::GetGameWidget() const
{
	return GameWidget;
}

void AGamePlayerController::SetCameraViewTarget(AActor* target)
{
	SetViewTargetWithBlend(target, .2f);
}

void AGamePlayerController::ClearCameraViewTarget()
{
	SetViewTargetWithBlend(GetPawn(), .2f);
}
