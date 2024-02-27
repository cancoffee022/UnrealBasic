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
	// ��ȣ�ۿ� ������ ������ ������ ó�� �߰ߵǴ� ���
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
	// ��ȣ�ۿ밡���� ��ü�� �������� ���� ���
	if (InteractableAreas.Num() < 1) return;

	FOnInterationFinishSignature onInteractionFinished;
	onInteractionFinished.AddUObject(this, &UPlayerCharacterInteractComponent::OnInteractionFinished);

	// ù ��° ��ȣ�ۿ� ���� ������Ʈ�� ����ϴ�
	UInteractableAreaComponent* interactableArea = InteractableAreas[0];


	bool isSucceeded = InteractableAreas[0]->StartInteraction(onInteractionFinished);

	if (isSucceeded)
	{
		// ��ȣ�ۿ� ���
		ANpcCharacter* npc = Cast<ANpcCharacter>(interactableArea->GetOwner());

		// ��ȣ�ۿ� ����
		OnInteractionStarted(
			npc->GetInterationLocation(),
			npc->GetInteractionRotation());

		ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
		Cast<AGamePlayerController>(playerCharacter->GetController())->SetCameraViewTarget(npc);
	}
}

void UPlayerCharacterInteractComponent::OnInteractionStarted(FVector interactionLocation, FRotator interactionRotation)
{
	// ���� ��ġ ����
	ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
	BeforeInteractionLocation = playerCharacter->GetMesh()->GetComponentLocation();
	BeforeInteractionRotation = playerCharacter->GetMesh()->GetComponentRotation();

	// ��ȣ�ۿ� ��ġ, ȸ�� ����
	playerCharacter->GetMesh()->SetWorldLocation(interactionLocation);
	playerCharacter->GetMesh()->SetWorldRotation(interactionRotation);

}

void UPlayerCharacterInteractComponent::OnInteractionFinished()
{
	// ��ȣ�ۿ� ��ġ, ȸ�� �ǵ�����
	ACharacter* playerCharacter = Cast<ACharacter>(GetOwner());
	playerCharacter->GetMesh()->SetWorldLocation(BeforeInteractionLocation);
	playerCharacter->GetMesh()->SetWorldRotation(BeforeInteractionRotation);

	Cast<AGamePlayerController>(playerCharacter->GetController())->ClearCameraViewTarget();

}

