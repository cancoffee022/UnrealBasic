#include "Component/KnightAttackComponent/KnightAttackComponent.h"
#include "Component/PlayerCharacterAttackComponent/PlayerCharacterAttackComponent.h"

#include "Actor/EnemyCharacter/Knight/KnightCharacter.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Structure/EnemyData/EnemyData.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UKnightAttackComponent::UKnightAttackComponent()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> MONTAGE_ATTACK(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/GKnight/Animation/AnimMontage_Attack.AnimMontage_Attack'"));
	if (MONTAGE_ATTACK.Succeeded())
	{
		AttackAnimMontage = MONTAGE_ATTACK.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> MONTAGE_PARRIED(
		TEXT("/Script/Engine.AnimMontage'/Game/Resources/EnemyCharacter/GKnight/Animation/AnimMontage_Parried.AnimMontage_Parried'"));
	
	if (MONTAGE_PARRIED.Succeeded())
	{
		ParriedAnimMontage = MONTAGE_PARRIED.Object;
	}

	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UKnightAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKnightAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsAttackAreaEnabled) CheackAttackArea();
}

bool UKnightAttackComponent::IsBlocked(AGameCharacter* gameCharacter, AActor* ownerEnemy) const
{
	// ĳ���� �� ����
	FVector gameCharacterForward = gameCharacter->GetActorForwardVector();

	// �� ĳ���� �չ���
	FVector enemyCharacterForward = GetOwner()->GetActorForwardVector();
	enemyCharacterForward *= -1;
	gameCharacterForward.Z = enemyCharacterForward.Z = 0;

	float angle = FMath::RadiansToDegrees(
		FMath::Acos(FVector::DotProduct(gameCharacterForward, enemyCharacterForward)));


	// ������̶��
	if (gameCharacter->GetAttackComponent()->GetBlockState() &&
		angle <= 30.f)
	{
		return true;
	}

	return false;
}

void UKnightAttackComponent::CheackAttackArea()
{
	if (!IsValid(SwordMeshComponent)) return;

	FVector checkStartLocation = SwordMeshComponent->GetSocketTransform(SWORD_SOCKET_START).GetLocation();
	FVector checkEndLocation = SwordMeshComponent->GetSocketTransform(SWORD_SOCKET_END).GetLocation();

	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(GetOwner());

	TArray<FHitResult> hitResults;

	UKismetSystemLibrary::SphereTraceMultiByProfile(
		this,
		checkStartLocation,
		checkEndLocation,
		10.f,
		TEXT("AttackArea"),
		false,
		actorsToIgnore,
		EDrawDebugTrace::ForOneFrame,
		hitResults,
		true);

	bool applyHalfDamage = false;

	for (FHitResult hitResult : hitResults)
	{
		// ������ ��ü ��, GameCharacter������ ��ü�� ����ϴ�.
		AGameCharacter* gameCharacter = Cast<AGameCharacter>(hitResult.GetActor());


		// ���� GameCharacter ��ü�� ������ ���
		if (IsValid(gameCharacter))
		{
			AKnightCharacter* knightCharacter = Cast<AKnightCharacter>(GetOwner());
			
			// ��� �Ǿ����� Ȯ���մϴ�
			bool isBlocked = IsBlocked(gameCharacter, GetOwner());

			// ��� ó���� ���
			if (isBlocked)
			{
				// ��Ȯ�� �ð��� ��� ������ Ȯ���մϴ�
				float currentTime = GetWorld()->GetTimeSeconds();
				float blockStartedTime = gameCharacter->GetAttackComponent()->GetBlockStartTime();

				applyHalfDamage = currentTime - blockStartedTime > 0.5f;

				knightCharacter->PlayAnimMontage(ParriedAnimMontage);

				// ���� ��
				OnAttackFinished();

				// ���� ���� ��Ȱ��ȭ
				DisableAttackArea();

				// ���ظ� ���� �ʾƵ� �Ǵ� ��� ����ó���� �̷������ �ʵ��� �մϴ�.
				if(!applyHalfDamage) return;
			}
			if (!isBlocked || applyHalfDamage)
			{
				// ���� �ߺ� ó��
				if (!TempDamagedActors.Contains(gameCharacter))
				{
					TempDamagedActors.Add(gameCharacter);

					// �÷��̾� ĳ���Ϳ��� ���ظ� �����ϴ�
					UGameplayStatics::ApplyDamage(
						gameCharacter,
						EnemyData->Atk * (applyHalfDamage ? 0.5f : 1.f),
						knightCharacter->GetController(),
						knightCharacter,
						UDamageType::StaticClass());
				}
			}
		}
	}
}

void UKnightAttackComponent::InitializeAttackComponent(UStaticMeshComponent* swordMeshComponent, FEnemyData* enemyData)
{
	SwordMeshComponent = swordMeshComponent;
	EnemyData = enemyData;
}

void UKnightAttackComponent::Attack()
{
	Cast<AKnightCharacter>(GetOwner())->PlayAnimMontage(AttackAnimMontage);
}

void UKnightAttackComponent::OnAttackFinished()
{
	TempDamagedActors.Empty();
}

void UKnightAttackComponent::EnableAttackArea()
{
	IsAttackAreaEnabled = true;
}

void UKnightAttackComponent::DisableAttackArea()
{
	IsAttackAreaEnabled = false;
}


