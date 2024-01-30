#include "Actor/EnemyCharacter/Chicken/ChickenCharacter.h"
#include "Actor/EnemyController/Chicken/ChickenController.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AnimInstance/ChickenCharacter/ChickenCharacterAnimInstance.h"


AChickenCharacter::AChickenCharacter()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> ANIMMONTAGE_ONHIT(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/AnimalVarietyPack/Chicken/Animations/AnimMontage_OnHit.AnimMontage_OnHit'"));

	if (ANIMMONTAGE_ONHIT.Succeeded())
	{
		OnHitAnimMontage = ANIMMONTAGE_ONHIT.Object;
	}

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

	// ��Ʈ�ѷ� ����
	SetEnemyController(AChickenController::StaticClass());
	
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

	// BlackboardKey �� �ʱ�ȭ�մϴ�
	InitializeBlackboardKey(blackboardComponent);
}

void AChickenCharacter::Tick(float dt)
{
	Super::Tick(dt); 
	
	float characterVelocity = GetVelocity().Length();
	// �ִ� �ν��Ͻ��� ����
	if (!IsValid(ControlledAnimInstance)) return;

	ControlledAnimInstance->SetCurrentSpeed(characterVelocity);
	ControlledAnimInstance->SetIsDead(IsDead);
}


void AChickenCharacter::SetAnimInstance(UChickenCharacterAnimInstance* controlledAnimInstance)
{
	ControlledAnimInstance = controlledAnimInstance;
}

void AChickenCharacter::OnDamaged(AGameCharacter* gameCharacter, float damage)
{
	Super::OnDamaged(gameCharacter, damage);

	if (!IsDead)
	{
		//OnHit �ִ� ��Ÿ�� ���
		PlayAnimMontage(OnHitAnimMontage);
	}
}

void AChickenCharacter::InitializeBlackboardKey(UBlackboardComponent* blackboardComponent)
{
	//SpawnLocation ����
	FVector spawnLocation = GetActorLocation();
	blackboardComponent->SetValueAsVector(BLACKBOARDKEY_SPAWNLOCATION, spawnLocation);
	
	// MaxMoveDistance ����
	blackboardComponent->SetValueAsFloat(BLACKBOARDKEY_MAXMOVEDISTANCE, 200.f);
}

