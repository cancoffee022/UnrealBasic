#include "Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Actor/GameCharacter/GameCharacter.h"

UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	AllowMovementInput = true;
	// ...
}

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UPlayerCharacterMovementComponent::HorizontalMove(float axis)
{
	// 컨트롤러 회전중 Yaw 회전만을 얻습니다.
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	FRotator yawRotation = FRotator(0.0f, gameCharacter->GetControlRotation().Yaw, 0.0f);

	FVector rightVector = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	//rightVector = Cast<AActor>(gameCharacter->GetController())->GetActorRightVector();
	gameCharacter->AddMovementInput(rightVector, axis);


}

void UPlayerCharacterMovementComponent::VerticalMove(float axis)
{
	axis = AllowMovementInput ? axis : 0;

	// 컨트롤러 회전중 Yaw 회전만을 얻습니다.
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

	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	gameCharacter->Jump();
}

void UPlayerCharacterMovementComponent::SetAllowMovementInput(bool allowMovementInput)
{
	AllowMovementInput = allowMovementInput;
}


