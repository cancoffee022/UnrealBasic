#include "PlayerController/GamePlayerController.h"

#include "Kismet/GameplayStatics.h"

// ī�޶� ���� �±�
#define TAG_CAMERA		TEXT("Camera")

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	FindCameraComponent();
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed, this, &ThisClass::OnJumpKeyPressed);
	// BindAction(
	// const FName ActionName,
	// �츮�� ��Ͻ�Ų Ű�̸�
	//
	// const EInputEvent KeyEvent,
	// Ű �̺�Ʈ Ÿ�� (Ű�� ������ ��, �������� ��)
	// 
	// UserClass* Object
	// �̺�Ʈ�� �����ϱ� ����(��� �Լ��� ȣ���ϱ� ����) ��ü
	// 
	// typename
	//
}

void AGamePlayerController::FindCameraComponent()
{
	// ī�޶� ���͸� ã�� �����ϱ� ���� �迭
	TArray<AActor*> findActors;

	// TAG_CAMER Tag�� ���� ���͸� ���忡�� ã���ϴ�
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TAG_CAMERA, findActors);
	// UGameplayStatics : ���� �÷��� �߿� ��밡���� ������ �޼������ �����ϴ� ���� Ŭ����
	// GetAllActorsWithTag(WorldContextObject,Tag, OutActors)
	// Tag�� ���� ���͸� WolrdContextObject���� ã�� OutActors �迭�� �߰��մϴ�

	// ã�� ī�޶� ���ͷ� �並 �����մϴ�.
	SetViewTargetWithBlend(findActors[0]);
}

void AGamePlayerController::OnJumpKeyPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump!"));
}
