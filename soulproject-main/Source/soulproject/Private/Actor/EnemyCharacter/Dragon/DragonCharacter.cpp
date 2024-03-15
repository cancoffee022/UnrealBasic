#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"
#include "Actor/EnemyController/Dragon/DragonController.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Component/DragonCharacterMovementComponent/DragonCharacterMovementComponent.h"

#include "Components/CapsuleComponent.h"

#include "AnimInstance/DragonCharacter/DragonCharacterAnimInstance.h"

ADragonCharacter::ADragonCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/DesertDragon/Meshes/SK_DesertDragon.SK_DesertDragon'"));

	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}

	static ConstructorHelpers::FClassFinder<UDragonCharacterAnimInstance> ANIMBP_DRAGON(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_DragonCharacter.AnimBP_DragonCharacter_C'"));
	if (ANIMBP_DRAGON.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_DRAGON.Class);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_MOVE(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/DesertDragon/Animations/AnimMontage_Move.AnimMontage_Move'"));
	if (ANIMMONTAGE_MOVE.Succeeded())
	{
		MoveAnimMontage = ANIMMONTAGE_MOVE.Object;
	}

	LeftForwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LFLEG"));
	LeftForwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_LFLeg"));

	LeftBackwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LBLEG"));
	LeftBackwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_LBLeg"));

	RightForwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RFLEG"));
	RightForwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_RFLeg"));

	RightBackwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RBLEG"));
	RightBackwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_RBLeg"));

	DragonMovementComponent = CreateDefaultSubobject<UDragonCharacterMovementComponent>(TEXT("MOVEMENT_COMP"));

	// 컨트롤러 설정
	SetEnemyController(ADragonController::StaticClass());

	// 적 코드 설정
	EnemyCode = TEXT("000004");

}

void ADragonCharacter::BeginPlay()
{
	Super::BeginPlay();

	UDragonCharacterAnimInstance* animInst = Cast<UDragonCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->OnTurn.AddUObject(DragonMovementComponent, &UDragonCharacterMovementComponent::StartTurn);
}

void ADragonCharacter::PlayMoveAnimMontage(FName playSectionName)
{
	PlayAnimMontage(MoveAnimMontage, 1.f, playSectionName);
}

void ADragonCharacter::OnPlayerCharacterDetected(AGameCharacter* gameCharacter)
{
	Cast<ADragonController>(GetController())->SetPlayerCharacterKey(gameCharacter);
}
