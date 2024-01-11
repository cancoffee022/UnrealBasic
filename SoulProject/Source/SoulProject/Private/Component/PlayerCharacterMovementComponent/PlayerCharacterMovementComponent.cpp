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
	// ��Ʈ�ѷ� ������ �̵��� ���Ǵ� InputVelocity�� �����Ѵ�

	AGameCharacter* playerCharacterActor = Cast<AGameCharacter>(GetOwner());

	// �÷��̾� ��Ʈ�ѷ��� ȸ���� ����ϴ�.
	FRotator controlRotation = Cast<AGameCharacter>(GetOwner())->GetControlRotation();

	// ���� �� �̵� ó��
	FRotator yawRotation = FRotator(0, controlRotation.Yaw, 0);

	// ������ ����
	FVector rightVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	rightVector *= InputVelocity.Y;
	// FRotationMatrix : ȸ���� ��ǥ�� ������ �����ϴ� ����� ��Ÿ���ϴ�
	// GetUnitAxis(EAxis) : EAxis �������� ������ ��ȯ�մϴ�
	
	// ���� ����
	FVector forwardVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	forwardVector *= InputVelocity.X;

	// �� ������ �����Ͽ� ���� ���͸� ����ϴ�.
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

