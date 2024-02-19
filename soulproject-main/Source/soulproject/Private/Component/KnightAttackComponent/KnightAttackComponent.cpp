#include "Component/KnightAttackComponent/KnightAttackComponent.h"

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

	for (FHitResult hitResult : hitResults)
	{
		// 감지된 객체 중, GameCharacter형태의 객체를 얻습니다.
		AGameCharacter* gameCharacter = Cast<AGameCharacter>(hitResult.GetActor());
		if (IsValid(gameCharacter))
		{
			AKnightCharacter* knightCharacter = Cast<AKnightCharacter>(GetOwner());

			// 플레이어 캐릭터에게 피해를 입힙니다
			UGameplayStatics::ApplyDamage(
				gameCharacter,
				EnemyData->Atk,
				knightCharacter->GetController(),
				knightCharacter,
				UDamageType::StaticClass());
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
}

void UKnightAttackComponent::EnableAttackArea()
{
	IsAttackAreaEnabled = true;
}

void UKnightAttackComponent::DisableAttackArea()
{
	IsAttackAreaEnabled = false;
}


