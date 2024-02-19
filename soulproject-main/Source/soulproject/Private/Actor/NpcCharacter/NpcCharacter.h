// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NpcCharacter.generated.h"

UCLASS()
class ANpcCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class UDataTable* DT_NpcData;

protected:
	// Npc �ڵ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString NpcCode;

public:
	// Sets default values for this character's properties
	ANpcCharacter();

protected:
	virtual void BeginPlay() override;

	// Npc ������ �ʱ�ȭ
	virtual void InitializeNpcData();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
