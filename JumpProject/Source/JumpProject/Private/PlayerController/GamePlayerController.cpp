#include "PlayerController/GamePlayerController.h"

#include "Kismet/GameplayStatics.h"

// 카메라 엑터 태그
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
	// 우리가 등록시킨 키이름
	//
	// const EInputEvent KeyEvent,
	// 키 이벤트 타입 (키가 눌렸을 떄, 떼어졌을 때)
	// 
	// UserClass* Object
	// 이벤트를 실행하기 위한(멤버 함수를 호출하기 위한) 객체
	// 
	// typename
	//
}

void AGamePlayerController::FindCameraComponent()
{
	// 카메라 액터를 찾아 저장하기 위한 배열
	TArray<AActor*> findActors;

	// TAG_CAMER Tag를 갖는 액터를 월드에서 찾습니다
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TAG_CAMERA, findActors);
	// UGameplayStatics : 게임 플레이 중에 사용가능한 유용한 메서드들을 제공하는 정적 클래스
	// GetAllActorsWithTag(WorldContextObject,Tag, OutActors)
	// Tag를 갖는 액터를 WolrdContextObject에서 찾아 OutActors 배열에 추가합니다

	// 찾은 카메라 액터로 뷰를 설정합니다.
	SetViewTargetWithBlend(findActors[0]);
}

void AGamePlayerController::OnJumpKeyPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump!"));
}
