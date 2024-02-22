// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/InteractableAreaComponent/InteractableAreaComponent.h"
#include "Component/PlayerCharacterInteractComponent/PlayerCharacterInteractComponent.h"

#include "Actor/GameCharacter/GameCharacter.h"
#include "Actor/NpcCharacter/NpcCharacter.h"

UInteractableAreaComponent::UInteractableAreaComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UInteractableAreaComponent::OnBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UInteractableAreaComponent::OnEndOverlap);
}

void UInteractableAreaComponent::StartInteraction()
{
	Cast<ANpcCharacter>(GetOwner())->OnInteractionStarted();
}

void UInteractableAreaComponent::OnBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AGameCharacter>())
	{
		AGameCharacter* gameCharacter = Cast<AGameCharacter>(OtherActor);

		// 상호작용 컴포넌트를 얻습니다.
		gameCharacter->GetInteractComponent()->AddInteractableArea(this);
	}
}

void UInteractableAreaComponent::OnEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex)
{
	if (OtherActor->IsA<AGameCharacter>())
	{
		AGameCharacter* gameCharacter = Cast<AGameCharacter>(OtherActor);

		// 상호작용 컴포넌트를 얻습니다.
		gameCharacter->GetInteractComponent()->RemoveInteractableArea(this);
	}
}
