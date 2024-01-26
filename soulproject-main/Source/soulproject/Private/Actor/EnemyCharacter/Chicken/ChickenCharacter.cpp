#include "Actor/EnemyCharacter/Chicken/ChickenCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AnimInstance/ChickenCharacter/ChickenCharacterAnimInstance.h"


AChickenCharacter::AChickenCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CHICKEN(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/AnimalVarietyPack/Chicken/Meshes/SK_Chicken.SK_Chicken'"));

	static ConstructorHelpers::FClassFinder<UChickenCharacterAnimInstance> ANIMBP_CHICKEN_CHARACTER(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBP_ChickenCharacter.AnimBP_ChickenCharacter_C'"));

	if (SK_CHICKEN.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHICKEN.Object);
	}

	if (ANIMBP_CHICKEN_CHARACTER.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ANIMBP_CHICKEN_CHARACTER.Class);
	}
	
	EnemyCode = TEXT("000001");

}
void AChickenCharacter::BeginPlay()
{
	Super::BeginPlay();
	ControlledAnimInstance = Cast<UChickenCharacterAnimInstance>(GetMesh()->GetAnimInstance());
}

void AChickenCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	UBlackboardComponent* blackboardComponent =
		Cast<AAIController>(NewController)->GetBlackboardComponent();

	// BlackboardKey 를 초기화합니다
	InitializeBlackboardKey(blackboardComponent);
}

void AChickenCharacter::Tick(float dt)
{
	Super::Tick(dt); 
	
	float characterVelocity = GetVelocity().Length();
	// 애님 인스턴스에 적용
	ControlledAnimInstance->SetCurrentSpeed(characterVelocity);

	UE_LOG(LogTemp, Warning, TEXT("%.2f"), characterVelocity);
}


void AChickenCharacter::SetAnimInstance(UChickenCharacterAnimInstance* controlledAnimInstance)
{
	ControlledAnimInstance = controlledAnimInstance;
}

void AChickenCharacter::InitializeBlackboardKey(UBlackboardComponent* blackboardComponent)
{
	//SpawnLocation 설정
	FVector spawnLocation = GetActorLocation();
	blackboardComponent->SetValueAsVector(BLACKBOARDKEY_SPAWNLOCATION, spawnLocation);
	
	// MaxMoveDistance 설정
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 200.f);
}

