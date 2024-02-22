// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterInteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterInteractComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	TArray<class UInteractableAreaComponent*> InteractableAreas;

public:	
	UPlayerCharacterInteractComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ��ȣ �ۿ� ���� ���� ��ü�� �߰��մϴ�
	void AddInteractableArea(class UInteractableAreaComponent* newArea);
		
	// ��ȣ �ۿ� ���� ���� ��ü�� �����մϴ�
	void RemoveInteractableArea(class UInteractableAreaComponent* newArea);

	// ��ȣ�ۿ� �õ�
	void TryInteraction();

};