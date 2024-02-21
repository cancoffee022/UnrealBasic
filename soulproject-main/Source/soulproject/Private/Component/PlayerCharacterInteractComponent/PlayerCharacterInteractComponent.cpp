// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/PlayerCharacterInteractComponent/PlayerCharacterInteractComponent.h"
#include "Component/InteractableAreaComponent/InteractableAreaComponent.h"

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
	if (InteractableAreas.Contains(newArea))
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

	// ��ȣ�ۿ�
	InteractableAreas[0]->StartInteraction();
}

