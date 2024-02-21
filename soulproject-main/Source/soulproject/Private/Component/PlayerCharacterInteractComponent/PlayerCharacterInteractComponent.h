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

	// 상호 작용 가능 영역 객체를 추가합니다
	void AddInteractableArea(class UInteractableAreaComponent* newArea);
		
	// 상호 작용 가능 영역 객체를 삭제합니다
	void RemoveInteractableArea(class UInteractableAreaComponent* newArea);

	// 상호작용 시도
	void TryInteraction();

};
