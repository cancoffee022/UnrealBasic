// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"

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

