// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NpcCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInterationFinishSignature)

UCLASS()
class ANpcCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	FOnInterationFinishSignature OnInteractionFinished;

	UPROPERTY()
	class UDataTable* DT_NpcData;

protected:
	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* NpcWidgetComponent;

	// ��ȣ�ۿ� ������ ����
	UPROPERTY(VisibleAnywhere)
	class UInteractableAreaComponent* InteractableAreaComponent;
	
	// ��ȣ�ۿ�� �÷��̾� ĳ���Ͱ� ��ġ�� ��ġ
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* InterationLocation;
	
	// ��ȣ�ۿ�� ������ �� ī�޶�
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* InteractionViewTargetCamera;

	// Npc �ڵ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName NpcCode;

	// Npc ����
	struct FNpcData* NpcData;

	// ������ Npc Dialog Widget
	UPROPERTY()
	class UNpcDialogWidget* NpcDialogWidget;

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

	virtual bool OnInteractionStarted(FOnInterationFinishSignature OnInteractionFinished);

	FORCEINLINE class UNpcDialogWidget* GetNpcDialogWidget() const
	{
		return NpcDialogWidget;
	}

	FORCEINLINE class UCameraComponent* GetInteractionViewTarget() const
	{
		return InteractionViewTargetCamera;
	}

	// ��ȣ�ۿ�� ��ġ�� ���� ��ġ�� ����ϴ�
	FVector GetInterationLocation() const;

	FRotator GetInteractionRotation() const;
};
