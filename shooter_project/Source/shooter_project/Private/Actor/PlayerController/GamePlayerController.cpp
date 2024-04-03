#include "Actor/PlayerController/GamePlayerController.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Widget/PlayerWidget/PlayerWidget.h"

AGamePlayerController::AGamePlayerController()
{
	static ConstructorHelpers::FClassFinder<UPlayerWidget> WIDGETBP_PLAYERWIDGET(
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/WIdgetBP_PlayerWidget.WIdgetBP_PlayerWidget_C'"));
	if (WIDGETBP_PLAYERWIDGET.Succeeded())
	{
		WidgetBP_PlayerWidget = WIDGETBP_PLAYERWIDGET.Class;
	}

}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ThisClass::OnJumpInput);
	InputComponent->BindAxis(TEXT("Horizontal"), this, &ThisClass::OnHorizontalInput);
	InputComponent->BindAxis(TEXT("Vertical"), this, &ThisClass::OnVerticalInput);

	InputComponent->BindAxis(TEXT("MouseX"), this, &ThisClass::OnMouseX);
	InputComponent->BindAxis(TEXT("MouseY"), this, &ThisClass::OnMouseY);

	InputComponent->BindAction(TEXT("GetItem"), EInputEvent::IE_Pressed, this, &ThisClass::OnGetItemPressed);

}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsLocalPlayerController()) return;

	// 플레이어 위젯을 생성합니다.
	PlayerWidget = CreateWidget<UPlayerWidget>(this, WidgetBP_PlayerWidget);

	// 플레이어 위젯을 화면에 표시합니다.
	PlayerWidget->AddToPlayerScreen();
}

void AGamePlayerController::OnGetItemPressed()
{
	APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (!IsValid(playerCharacter)) return;

	playerCharacter->OnGetItemPressed();
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

void AGamePlayerController::OnJumpInput()
{
	APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(GetPawn());
	if (!IsValid(playerCharacter)) return;

	playerCharacter->OnJumpInput();
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
