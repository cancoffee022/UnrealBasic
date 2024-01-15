// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterAnimController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerCharacterAnimController : public UActorComponent
{
	GENERATED_BODY()

private:
	// �� ������Ʈ�� ������ �ִ� �ν��Ͻ��Դϴ�.
	class UPlayerCharacterAnimInstance* ControlledAnimInstance;

public:	
	// Sets default values for this component's properties
	UPlayerCharacterAnimController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
