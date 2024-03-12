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
	// 캐릭터 앞 방향
	FVector gameCharacterForward = gameCharacter->GetActorForwardVector();

	// 적 캐릭터 앞방향
	FVector enemyCharacterForward = GetOwner()->GetActorForwardVector();
	enemyCharacterForward *= -1;
	gameCharacterForward.Z = enemyCharacterForward.Z = 0;

	float angle = FMath::RadiansToDegrees(
		FMath::Acos(FVector::DotProduct(gameCharacterForward, enemyCharacterForward)));


	// 방어중이라면
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
		// 감지된 객체 중, GameCharacter형태의 객체를 얻습니다.
		AGameCharacter* gameCharacter = Cast<AGameCharacter>(hitResult.GetActor());


		// 만약 GameCharacter 객체를 감지한 경우
		if (IsValid(gameCharacter))
		{
			AKnightCharacter* knightCharacter = Cast<AKnightCharacter>(GetOwner());
			
			// 방어 되었음을 확인합니다
			bool isBlocked = IsBlocked(gameCharacter, GetOwner());

			// 방어 처리된 경우
			if (isBlocked)
			{
				// 정확한 시간에 방어 했음을 확인합니다
				float currentTime = GetWorld()->GetTimeSeconds();
				float blockStartedTime = gameCharacter->GetAttackComponent()->GetBlockStartTime();

				applyHalfDamage = currentTime - blockStartedTime > 0.5f;

				knightCharacter->PlayAnimMontage(ParriedAnimMontage);

				// 공격 끝
				OnAttackFinished();

				// 공격 영역 비활성화
				DisableAttackArea();

				// 피해를 주지 않아도 되는 경우 공격처리가 이루어지지 않도록 합니다.
				if(!applyHalfDamage) return;
			}
			if (!isBlocked || applyHalfDamage)
			{
				// 공격 중복 처리
				if (!TempDamagedActors.Contains(gameCharacter))
				{
					TempDamagedActors.Add(gameCharacter);

					// 플레이어 캐릭터에게 피해를 입힙니다
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


