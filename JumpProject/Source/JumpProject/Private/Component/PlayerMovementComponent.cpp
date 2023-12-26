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

	// �߷��� �����ŵ�ϴ�
	ApplyGravity();

	// �̵���ŵ�ϴ�
	Move();
}

void UPlayerMovementComponent::Jump()
{
	// �ִ� ���̸� �ʰ��ϴ� ��� ���� ���
	if (GetOwner()->GetActorLocation().Z > MaxHeight) return;

	Velocity.Z = JumpPower;
}

void UPlayerMovementComponent::ApplyGravity()
{
	// �ϰ� �ӵ��� ������Ų��
	Velocity.Z -= FMath::Abs(GetWorld()->GetGravityZ()) * GravityMultiplier;
}

void UPlayerMovementComponent::Move()
{
	// ���� ������ ��ġ�� ����ϴ�.
	FVector currentLocation = GetOwner()->GetActorLocation();
	// GetOwner() : �� ������Ʈ�� �����ϴ� ���� ��ü�� ��ȯ�մϴ�.
	
	// ���Ϳ� ������ų ��ġ�� ����մϴ�.
	FVector nextLocation = currentLocation + Velocity;

	// ������ ��ġ�� �����մϴ�
	GetOwner()->SetActorLocation(nextLocation);
}

