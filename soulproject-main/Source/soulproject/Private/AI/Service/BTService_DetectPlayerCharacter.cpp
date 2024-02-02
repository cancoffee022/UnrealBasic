#include "AI/Service/BTService_DetectPlayerCharacter.h"

#include "Actor/GameCharacter/GameCharacter.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Kismet/KismetSystemLibrary.h"

UBTService_DetectPlayerCharacter::UBTService_DetectPlayerCharacter()
{
	IsAttackRequestedKey.AddBoolFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, IsAttackRequestedKey));
}

void UBTService_DetectPlayerCharacter::TickNode(UBehaviorTreeComponent& ownerComponent, uint8* nodeMemory, float dt)
{
	Super::TickNode(ownerComponent, nodeMemory, dt);

	CheckArea(ownerComponent);
}

void UBTService_DetectPlayerCharacter::CheckArea(UBehaviorTreeComponent& ownerComponent)
{
	AController* ownerController= Cast<AController>(ownerComponent.GetOwner());

	// 이 액터의 위치
	FVector currentLocation = ownerController->GetPawn()->GetActorLocation();

	// 감지 반경
	float radius = 50.f;

	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypeQuery;
	objectTypeQuery.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> actorsToIgnore;
	TArray<AActor*> detectedActors;

	if (UKismetSystemLibrary::SphereOverlapActors(
		ownerComponent.GetOwner(),
		currentLocation + (ownerController->GetPawn()->GetActorForwardVector() * radius),
		radius,
		objectTypeQuery,
		AGameCharacter::StaticClass(),
		actorsToIgnore,
		detectedActors
	))
	{
		for (AActor* detectedActor : detectedActors)
		{
			UE_LOG(LogTemp, Warning, TEXT("Detected [%s]"), *detectedActor->GetName());
		}
	}
}
