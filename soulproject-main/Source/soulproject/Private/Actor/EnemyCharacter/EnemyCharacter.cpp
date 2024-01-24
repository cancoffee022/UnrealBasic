#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "Actor/EnemyController/EnemyController.h"

#include "Structure/EnemyData/EnemyData.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ENEMY_DATA(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_EnemyData.DT_EnemyData'"));
	if (DT_ENEMY_DATA.Succeeded())
	{
		EnemyDataTable = DT_ENEMY_DATA.Object;
	}

 	// 사용하는 AI 컨트롤러 클래스를 설정합니다
	AIControllerClass = AEnemyController::StaticClass();

	// 컨트롤러 생성방식을 정의합니다
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;


	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnDamaged);

}

void AEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 적 정보 초기화
	InitializeEnemyData();

	if (EnemyData == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyData is notValide (EnemyCode :%s)"), *EnemyData->Name.ToString());
	}
	else
	{
		AEnemyController* enemyController = Cast<AEnemyController>(NewController);
		enemyController->InitializeEnemyController(EnemyData);
	}
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::InitializeEnemyData()
{
	if (EnemyCode.IsNone()) return;

	FString contextString;
	EnemyData = EnemyDataTable->FindRow<FEnemyData>(EnemyCode, contextString);

	if (EnemyData != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Name = %s"), *EnemyData->Name.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void AEnemyCharacter::OnDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage = %.2f"), Damage);
}


