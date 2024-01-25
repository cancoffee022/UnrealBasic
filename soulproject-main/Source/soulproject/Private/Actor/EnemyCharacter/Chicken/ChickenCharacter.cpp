#include "Actor/EnemyCharacter/Chicken/ChickenCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ChickenCharacter.h"

AChickenCharacter::AChickenCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CHICKEN(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/EnemyCharacter/AnimalVarietyPack/Chicken/Meshes/SK_Chicken.SK_Chicken'"));
	if (SK_CHICKEN.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHICKEN.Object);
	}
	
	EnemyCode = TEXT("000001");
}

void AChickenCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	UBlackboardComponent* blackboardComponent =
		Cast<AAIController>(NewController)->GetBlackboardComponent();

	// BlackboardKey �� �ʱ�ȭ�մϴ�
	InitializeBlackboardKey(blackboardComponent);

}

void AChickenCharacter::InitializeBlackboardKey(UBlackboardComponent* blackboardComponent)
{
	//SpawnLocation ����
	FVector spawnLocation = GetActorLocation();
	blackboardComponent->SetValueAsVector(BLACKBOARDKEY_SPAWNLOCATION, spawnLocation);
	
	// MaxMoveDistance ����
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 200.f);
}
