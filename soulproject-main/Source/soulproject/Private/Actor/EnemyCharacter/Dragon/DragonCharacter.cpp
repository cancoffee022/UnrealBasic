#include "Actor/EnemyCharacter/Dragon/DragonCharacter.h"
#include "Actor/EnemyController/Dragon/DragonController.h"

#include "Components/CapsuleComponent.h"

ADragonCharacter::ADragonCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/DesertDragon/Meshes/SK_DesertDragon.SK_DesertDragon'"));

	if (SK_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	LeftForwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LFLEG"));
	LeftForwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_LFLeg"));

	LeftBackwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("LBLEG"));
	LeftBackwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_LBLeg"));

	RightForwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RFLEG"));
	RightForwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_RFLeg"));

	RightBackwardLeg = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RBLEG"));
	RightBackwardLeg->SetupAttachment(GetMesh(), TEXT("Socket_RBLeg"));
	

	// 컨트롤러 설정
	SetEnemyController(ADragonController::StaticClass());

	// 적 코드 설정
	EnemyCode = TEXT("000004");

}
