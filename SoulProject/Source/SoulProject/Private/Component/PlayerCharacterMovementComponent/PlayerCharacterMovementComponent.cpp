#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"

// Sets default values for this component's properties
UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Movement();
}

void UPlayerCharacterMovementComponent::OnMovementInput(FVector2D inputVector)
{
	InputVelocity = FVector(inputVector.Y, inputVector.X , 0);
}

void UPlayerCharacterMovementComponent::Movement()
{
	// 컨트롤러 방향을 이동에 사용되는 InputVelocity에 연산한다

	AGameCharacter* playerCharacterActor = Cast<AGameCharacter>(GetOwner());

	// 플레이어 컨트롤러의 회전을 얻습니다.
	FRotator controlRotation = Cast<AGameCharacter>(GetOwner())->GetControlRotation();

	// 수평 축 이동 처리
	FRotator yawRotation = FRotator(0, controlRotation.Yaw, 0);

	// 오른쪽 방향
	FVector rightVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	rightVector *= InputVelocity.Y;
	// FRotationMatrix : 회전된 좌표계 정보를 저장하는 행렬을 나타냅니다
	// GetUnitAxis(EAxis) : EAxis 축으로의 방향을 반환합니다
	
	// 앞쪽 방향
	FVector forwardVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	forwardVector *= InputVelocity.X;

	// 두 방향을 연산하여 단위 벡터를 얻습니다.
	FVector direction = (rightVector + forwardVector).GetSafeNormal();

	playerCharacterActor->AddMovementInput(direction, 1.0f);

	//FVector controlForward = Cast<AActor>(playerCharacterActor->GetController())->
	//	GetActorForwardVector();
	//controlForward.Y = 0;
	//controlForward = controlForward.GetSafeNormal();

	//FVector controlRight = Cast<AActor>(playerCharacterActor->GetController())->
	//	GetActorRightVector();

	//direction = (rightVector + forwardVector).GetSafeNormal();
}

