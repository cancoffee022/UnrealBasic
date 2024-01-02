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

	// �߷��� �����ŵ�ϴ�
	ApplyGravity();

	// �浹ü �˻�
	CheckCollision();

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

void UPlayerMovementComponent::CheckCollision()
{
	// ��(sphere) Ʈ���̽� �߻� ��ġ�� ����մϴ�
	FVector startLocation = GetOwner()->GetActorLocation();
		

	// �� Ʈ���̽� �߻� �� ��ġ�� ����մϴ�
	FVector endLocation = startLocation + 
		// �ӵ� ���� + �� ũ�� ����
		(FVector(0, 0, FMath::Sign(Velocity.Z)) * (FMath::Abs(Velocity.Z) + FGameConstants::GetPlayerSphereRadius()));

	// �� Ʈ���̽� �������� ���ܽ�ų ����
	TArray<AActor*> actorsToIgnore = { GetOwner() };

	// ���� ���
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
		// �÷��̾�� �浹�� ������Ʈ�� ����ϤӤӴ�
		UStaticMeshComponent* lineObject = Cast<UStaticMeshComponent>(hitResult.GetComponent());
		
		// LineObject �� �浹�� ���
		if (lineObject != nullptr)
		{
			// �浹�� LineGroupActor�� ����ϴ�
			ALineGroupActor* lineGroup = Cast<ALineGroupActor>(hitResult.GetActor());

			// ��� ������ lineObject���� Ȯ���մϴ�
			if (lineGroup->IsPassableLineObject(lineObject))
			{
				// ���� ��� �̺�Ʈ�� �߻���ŵ�ϴ�
				OnLinePassedEvent.ExecuteIfBound(lineGroup);

				Jump();
			}
		}

		// ������ ��ġ
		//FVector hitLocation = hitResult.Location;
	}
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

void UPlayerMovementComponent::SetLinePassedEvent(FOnLinePassedEventSignature onLinePassedEvent)
{
	OnLinePassedEvent = onLinePassedEvent;
}

