#include "Component/PlayerCharacterAnimController/PlayerCharacterAnimController.h"
#include "../../AnimInstance/PlayerCharacter/PlayerCharacterAnimInstance.h"
#include "../../Actor/GameCharacter/GameCharacter.h"
#include "../../Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UPlayerCharacterAnimController::UPlayerCharacterAnimController()
{

	PrimaryComponentTick.bCanEverTick = true;

	OwnerCharacter = Cast<AGameCharacter>(GetOwner());

	// ...
}


// Called when the game starts
void UPlayerCharacterAnimController::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<AGameCharacter>(GetOwner());
}

void UPlayerCharacterAnimController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// �ӷ��� ����ϴ�.
	FVector characterVelocity = OwnerCharacter->GetVelocity();
	characterVelocity.Z = 0.f;
	float xySpeed = characterVelocity.Length();

	// �ӷ��� �����մϴ�.
	ControlledAnimInstance->SetCurrentSpeed(xySpeed);

	// ���� ���� ���¸� �����մϴ�.
	//bool isInAir = OwnerCharacter->GetMovementComponent()->IsFalling();
	bool isGrounded = OwnerCharacter->GetMovementComponent()->IsMovingOnGround();
	ControlledAnimInstance->SetGoundedState(isGrounded);
}

void UPlayerCharacterAnimController::SetAnimInstance(UPlayerCharacterAnimInstance* controlledAnimInstance)
{
	ControlledAnimInstance = controlledAnimInstance;
	ControlledAnimInstance->SetAnimController(this);
}

void UPlayerCharacterAnimController::OnAttackEnded()
{
	OwnerCharacter->GetAttackComponent()->ClearCurrentAttack();
}

void UPlayerCharacterAnimController::OnNextAttackCheckStarted()
{
	onNextAttackInputCheckStarted.ExecuteIfBound();
}

void UPlayerCharacterAnimController::OnNextAttackCheckFinished()
{
	onNextAttackInputCheckFinished.ExecuteIfBound();
}

void UPlayerCharacterAnimController::EnableAttackArea()
{
	onAttackAreaEnable.ExecuteIfBound();
}

void UPlayerCharacterAnimController::DisalbeAttackArea()
{
	onAttackAreaDisable.ExecuteIfBound();
}

void UPlayerCharacterAnimController::AllowMovementInput(bool allowMovementInput)
{
	onAllowMovementInput.ExecuteIfBound(allowMovementInput);
}
