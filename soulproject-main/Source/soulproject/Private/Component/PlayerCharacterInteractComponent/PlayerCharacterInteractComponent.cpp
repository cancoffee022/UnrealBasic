// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerCharacterInteractComponent/PlayerCharacterInteractComponent.h"
#include "Component/InteractableAreaComponent/InteractableAreaComponent.h"

#include "Actor/NpcCharacter/NpcCharacter.h"
#include "Actor/PlayerController/GamePlayerController.h"

// Sets default values for this component's properties
UPlayerCharacterInteractComponent::UPlayerCharacterInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCharacterInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerCharacterInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerCharacterInteractComponent::AddInteractableArea(UInteractableAreaComponent* newArea)
{
	// 상호작용 가능한 영역을 나간후 처음 발견되는 경우
	if (!InteractableAreas.Contains(newArea))
		InteractableAreas.Add(newArea);
}

void UPlayerCharacterInteractComponent::RemoveInteractableArea(UInteractableAreaComponent* newArea)
{
	if (InteractableAreas.Contains(newArea))
		InteractableAreas.Remove(newArea);
}

void UPlayerCharacterInteractComponent::TryInteraction()
{
	// 상호작용가능한 객체가 존재하지 않을 경우
	if (InteractableAreas.Num() < 1) return;

	FOnInterationFinishSignature onInteractionFinished;
	onInteractionFinished.AddUObject(this, &UPlayerCharacterInteractComponent::OnInteractionFinished);

	// 첫 번째 상호작용 영역 컴포넌트를 얻습니다
	UInteractableAreaComponent* interactableArea = InteractableAreas[0];


	bool isSucceeded = InteractableAreas[0]->StartInteraction(onInteractionFinished);

	if (isSucceeded)
	{
		// 상호작용 대상
		ANpcCharacter* npc = Cast<ANpcCharacter>(interactableArea->GetOwner());

		// 상호작용 시작
		OnInteractionStarted(
			npc->GetInterationLocation(),
			npc->GetInteractionRotation());

		ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
		Cast<AGamePlayerController>(playerCharacter->GetController())->SetCameraViewTarget(npc);
	}
}

void UPlayerCharacterInteractComponent::OnInteractionStarted(FVector interactionLocation, FRotator interactionRotation)
{
	// 이전 위치 저장
	ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
	BeforeInteractionLocation = playerCharacter->GetMesh()->GetComponentLocation();
	BeforeInteractionRotation = playerCharacter->GetMesh()->GetComponentRotation();

	// 상호작용 위치, 회전 설정
	playerCharacter->GetMesh()->SetWorldLocation(interactionLocation);
	playerCharacter->GetMesh()->SetWorldRotation(interactionRotation);

}

void UPlayerCharacterInteractComponent::OnInteractionFinished()
{
	// 상호작용 위치, 회전 되돌리기
	ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
	playerCharacter->GetMesh()->SetWorldLocation(BeforeInteractionLocation);
	playerCharacter->GetMesh()->SetWorldRotation(BeforeInteractionRotation);

	Cast<AGamePlayerController>(playerCharacter->GetController())->ClearCameraViewTarget();

}

