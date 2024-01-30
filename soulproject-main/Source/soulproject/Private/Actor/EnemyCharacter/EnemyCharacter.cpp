#include "Actor/EnemyCharacter/EnemyCharacter.h"
#include "Actor/EnemyController/EnemyController.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Components/CapsuleComponent.h"

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

	SetEnemyController(AEnemyController::StaticClass());

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

	// 매터리얼 파라미터 설정
	if (IsDead)
	{
		if (IsValid(MaterialInstanceOnDead))
		{
			float alpha;
			MaterialInstanceOnDead->GetScalarParameterValue(TEXT("_Alpha"), alpha);
			alpha -= 1.0f;
			MaterialInstanceOnDead->SetScalarParameterValue(TEXT("_Alpha"), alpha);
		}
	}
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
		CurrentHp = EnemyData->MaxHP;
	}
}

void AEnemyCharacter::OnDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	AEnemyController* enemyController = Cast<AEnemyController>(GetController());
	AGameCharacter* gameCharacter = Cast<AGameCharacter>(DamageCauser);

	if (IsValid(gameCharacter) && IsValid(enemyController))
	{
		float calculatedDamage = CalculateDamage(Damage);
		enemyController->OnDamaged(gameCharacter, calculatedDamage);
		OnDamaged(gameCharacter, calculatedDamage);
	}
}

void AEnemyCharacter::SetEnemyController(TSubclassOf<class AEnemyController> controllerClass, EAutoPossessAI possessType)
{
	AIControllerClass = controllerClass;
	AutoPossessAI = possessType;
}

void AEnemyCharacter::OnDamaged(AGameCharacter* gameCharacter, float damage)
{
	CurrentHp -= damage;

	if (CurrentHp <= 0)
	{
		CurrentHp = 0;

		// 사망 이벤트 실행
		AEnemyController* enemyController = Cast<AEnemyController>(GetController());

		enemyController->OnDead();
		OnDead();
	}
}

void AEnemyCharacter::OnDead()
{
	// 사망 상태 설정
	IsDead = true;

	// 사망 후 캐릭터가 통과할 수 있도록 컬리전 프리셋 설정
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("NoCollision"));

	// 매터리얼 설정
	MaterialInstanceOnDead = UMaterialInstanceDynamic::Create(EnemyData->MaterialInstanceOnDead, this);
	
	GetMesh()->SetMaterial(0, MaterialInstanceOnDead);

}

float AEnemyCharacter::CalculateDamage(float damage)
{
	return damage;
}


