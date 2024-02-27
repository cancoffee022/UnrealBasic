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

	// 상호작용 가능한 영역
	UPROPERTY(VisibleAnywhere)
	class UInteractableAreaComponent* InteractableAreaComponent;
	
	// 상호작용시 플레이어 캐릭터가 배치될 위치
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* InterationLocation;
	
	// 상호작용시 설정될 뷰 카메라
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* InteractionViewTargetCamera;

	// Npc 코드
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName NpcCode;

	// Npc 정보
	struct FNpcData* NpcData;

	// 생성된 Npc Dialog Widget
	UPROPERTY()
	class UNpcDialogWidget* NpcDialogWidget;

public:
	// Sets default values for this character's properties
	ANpcCharacter();

protected:
	virtual void BeginPlay() override;

	// Npc 데이터 초기화
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

	// 상호작용시 배치될 월드 위치를 얻습니다
	FVector GetInterationLocation() const;

	FRotator GetInteractionRotation() const;
};
