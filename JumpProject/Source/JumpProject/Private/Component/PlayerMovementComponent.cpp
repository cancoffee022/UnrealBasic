#include "Component/PlayerMovementComponent.h"

#include "../GameConstants.h"
#include "Kismet/KismetSystemLibrary.h"

#include "../Actor/LineGroupActor.h"

#include "Engine/World.h"

// Sets default values for this component's properties
UPlayerMovementComponent::UPlayerMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 중력을 적용시킵니다
	ApplyGravity();

	// 충돌체 검사
	CheckCollision();

	// 이동시킵니다
	Move();
}

void UPlayerMovementComponent::Jump()
{
	// 최대 높이를 초과하는 경우 점프 취소
	if (GetOwner()->GetActorLocation().Z > MaxHeight) return;

	Velocity.Z = JumpPower;
}

void UPlayerMovementComponent::ApplyGravity()
{
	// 하강 속도를 증가시킨다
	Velocity.Z -= FMath::Abs(GetWorld()->GetGravityZ()) * GravityMultiplier;
}

void UPlayerMovementComponent::CheckCollision()
{
	// 구(sphere) 트레이싱 발사 위치를 계산합니다
	FVector startLocation = GetOwner()->GetActorLocation();
		

	// 구 트레이싱 발사 끝 위치를 계산합니다
	FVector endLocation = startLocation + 
		// 속도 연산 + 구 크기 연산
		(FVector(0, 0, FMath::Sign(Velocity.Z)) * (FMath::Abs(Velocity.Z) + FGameConstants::GetPlayerSphereRadius()));

	// 구 트레이싱 감지에서 제외시킬 엑터
	TArray<AActor*> actorsToIgnore = { GetOwner() };

	// 감지 결과
	FHitResult hitResult;

	bool isHit = UKismetSystemLibrary::SphereTraceSingleByProfile(
		GetWorld(),
		startLocation,
		endLocation,
		FGameConstants::GetPlayerSphereRadius(),
		FName(TEXT("BlockAll")),
		false,
		actorsToIgnore,
		EDrawDebugTrace::Type::None,
		hitResult,
		true);

	if (isHit)
	{
		// 플레이어와 충돌한 컴포넌트를 얻습니ㅣㅣ다
		UStaticMeshComponent* lineObject = Cast<UStaticMeshComponent>(hitResult.GetComponent());
		
		// LineObject 와 충돌한 경우
		if (lineObject != nullptr)
		{
			// 충돌한 LineGroupActor를 얻습니다
			ALineGroupActor* lineGroup = Cast<ALineGroupActor>(hitResult.GetActor());

			// 통과 가능한 lineObject인지 확인합니다
			if (lineGroup->IsPassableLineObject(lineObject))
			{
				// 라인 통과 이벤트를 발생시킵니다
				OnLinePassedEvent.ExecuteIfBound(lineGroup);

				Jump();
			}
		}

		// 감지된 위치
		//FVector hitLocation = hitResult.Location;
	}
}

void UPlayerMovementComponent::Move()
{
	// 현재 액터의 위치를 얻습니다.
	FVector currentLocation = GetOwner()->GetActorLocation();
	// GetOwner() : 이 컴포넌트를 소유하는 액터 객체를 반환합니다.
	
	// 액터에 설정시킬 위치를 계산합니다.
	FVector nextLocation = currentLocation + Velocity;

	// 액터의 위치를 설정합니다
	GetOwner()->SetActorLocation(nextLocation);
}

void UPlayerMovementComponent::SetLinePassedEvent(FOnLinePassedEventSignature onLinePassedEvent)
{
	OnLinePassedEvent = onLinePassedEvent;
}

