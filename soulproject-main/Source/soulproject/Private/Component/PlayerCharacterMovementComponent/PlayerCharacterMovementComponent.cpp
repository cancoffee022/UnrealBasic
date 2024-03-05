#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_ROLL(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/GirlKnight1/Animations/Roll/AnimMontage_Roll.AnimMontage_Roll'"));
	if (ANIMMONTAGE_ROLL.Succeeded())
	{
		RollAnimMontage = ANIMMONTAGE_ROLL.Object;
	}


	PrimaryComponentTick.bCanEverTick = true;
	AllowMovementInput = true;

	RollInputTime = -10.f;
	PrevRollInputDirection = FIntVector2(0, 0);
	// ...
}

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	GameCharacter = Cast<AGameCharacter>(GetOwner());
	
}

void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UPlayerCharacterMovementComponent::HorizontalMove(float axis)
{
	// ��Ʈ�ѷ� ȸ���� Yaw ȸ������ ����ϴ�.
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotation = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector rightVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	//rightVector = Cast<AActor>(gameCharacter->GetController())->GetActorRightVector();
	gameCharacter->AddMovementInput(rightVector, axis);


}

void UPlayerCharacterMovementComponent::VerticalMove(float axis)
{
	axis = AllowMovementInput ? axis : 0;

	// ��Ʈ�ѷ� ȸ���� Yaw ȸ������ ����ϴ�.
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotation = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector forwardVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);

	//FVector controllerForward = Cast<AActor>(gameCharacter->GetController())->GetActorForwardVector();
	//controllerForward.Z = 0.0f;
	//forwardVector = controllerForward.GetUnsafeNormal();

	gameCharacter->AddMovementInput(forwardVector, axis);
}

void UPlayerCharacterMovementComponent::OnJump()
{
	// ������ �̵����̶�� ���� �ȵ�
	if (IsRollingMovement) return;

	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	gameCharacter->Jump();
}

void UPlayerCharacterMovementComponent::OnHit()
{
	AllowMovementInput = false;
}

void UPlayerCharacterMovementComponent::OnRollInput(FIntVector2 inputDirection)
{
	// ���� Ŭ������ �νĵǵ��� �� �ð���
	const float DOUBLE_INPUT_TIMETERM = .2f;

	// �Էµ� ���� �ð��� ����ϴ�
	float inputTime = GetWorld()->GetTimeSeconds();

	// ������ �Է��� ����� ������ ���
	if (inputDirection == PrevRollInputDirection &&
		// ���� Ŭ������ �Էµ� �ð��ȿ� �Է��� ���
		inputTime < RollInputTime + DOUBLE_INPUT_TIMETERM)
	{
		// ������ ����
		FVector rollingDirection = FVector(PrevRollInputDirection.Y, PrevRollInputDirection.X, 0);
		RollingMovement(rollingDirection);

		// �������� �ʱ�ȭ
		RollInputTime = 0;
		PrevRollInputDirection = FIntVector2(0, 0);
	}
	else
	{
		// �Է� �ð��� ����մϴ�
		RollInputTime = inputTime;

		// �Է� ������ ����մϴ�
		PrevRollInputDirection = inputDirection;
	}
}

void UPlayerCharacterMovementComponent::OnRollFinished()
{
	IsRollingMovement = false;
}

void UPlayerCharacterMovementComponent::SetAllowMovementInput(bool allowMovementInput)
{
	AllowMovementInput = allowMovementInput;
	// �̵� �Է� ���
	AllowMovementInput = true;
}

void UPlayerCharacterMovementComponent::AddImpulse(FVector direction, float power)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	gameCharacter->GetCharacterMovement()->AddImpulse(direction * power);
}

void UPlayerCharacterMovementComponent::RollingMovement(FVector rollDirection)
{
	// ���߿����� ������� �ʵ��� �մϴ�
	if (!GameCharacter->GetCharacterMovement()->IsMovingOnGround()) return;

	// ������ �̵����� ��� ������� �ʵ��� �մϴ�
	if (IsRollingMovement) return;

	// ������ �Է������� ������ ����
	IsRollingMovement = true;

	// �̵� �Է� ����
	AllowMovementInput = false;
	
	// ���� ���⿡ ���� Yaw ȸ����
	float worldYawAngle = FMath::RadiansToDegrees(FMath::Atan2(rollDirection.Y, rollDirection.X));

	// ���� ĳ������ Yaw ȸ����
	float characterYawAngle = GameCharacter->GetControlRotation().Yaw;

	// ������ �������� ȸ����ŵ�ϴ�
	GameCharacter->SetActorRotation(FRotator(0, worldYawAngle + characterYawAngle, 0));

	// �ִϸ��̼� ��Ÿ�� ���
	GameCharacter->PlayAnimMontage(RollAnimMontage);
}


