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
	// 구르기 이동중이라면 실행 안됨
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
	// 더블 클릭으로 인식되도록 할 시간텀
	const float DOUBLE_INPUT_TIMETERM = .2f;

	// 입력된 현재 시간을 얻습니다
	float inputTime = GetWorld()->GetTimeSeconds();

	// 이전에 입력한 방향과 동일한 경우
	if (inputDirection == PrevRollInputDirection &&
		// 더블 클릭으로 입력될 시간안에 입력한 경우
		inputTime < RollInputTime + DOUBLE_INPUT_TIMETERM)
	{
		// 구르기 실행
		FVector rollingDirection = FVector(PrevRollInputDirection.Y, PrevRollInputDirection.X, 0);
		RollingMovement(rollingDirection);

		// 이전값들 초기화
		RollInputTime = 0;
		PrevRollInputDirection = FIntVector2(0, 0);
	}
	else
	{
		// 입력 시간을 기록합니다
		RollInputTime = inputTime;

		// 입력 방향을 기록합니다
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
	// 이동 입력 허용
	AllowMovementInput = true;
}

void UPlayerCharacterMovementComponent::AddImpulse(FVector direction, float power)
{
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(GetOwner());
	gameCharacter->GetCharacterMovement()->AddImpulse(direction * power);
}

void UPlayerCharacterMovementComponent::RollingMovement(FVector rollDirection)
{
	// 공중에서는 실행되진 않도록 합니다
	if (!GameCharacter->GetCharacterMovement()->IsMovingOnGround()) return;

	// 구르기 이동중인 경우 실행되지 않도록 합니다
	if (IsRollingMovement) return;

	// 구르기 입력중임을 참으로 설정
	IsRollingMovement = true;

	// 이동 입력 막기
	AllowMovementInput = false;
	
	// 월드 방향에 대한 Yaw 회전각
	float worldYawAngle = FMath::RadiansToDegrees(FMath::Atan2(rollDirection.Y, rollDirection.X));

	// 현재 캐릭터의 Yaw 회전각
	float characterYawAngle = GameCharacter->GetControlRotation().Yaw;

	// 구르는 방향으로 회전시킵니다
	GameCharacter->SetActorRotation(FRotator(0, worldYawAngle + characterYawAngle, 0));

	// 애니메이션 몽타주 재생
	GameCharacter->PlayAnimMontage(RollAnimMontage);
}


