// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enum/WorldItemType.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHOOTER_PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()



protected:
// SpringArm 컴포넌트 추가
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComponent;


	// 입력 축 값을 나타냅니다
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	FIntVector InputAxisRaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	float CurrentSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	EWorldItemType EquippedItemType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsFireStarted;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AGunActor* EquippedGunActor;


private:
	// 겹친 World Item 액터들을 나타냅니다
	UPROPERTY()
	TArray<class AWorldItemActor*> OverlappedWorldItems;

public:
	// Sets default values for this character's properties
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void OnPlayerCharacterBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerCharacterEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	// 겹친 WorldItem 액터를 추가합니다.
	void AddOverlappedWorldItem(class AWorldItemActor* worldItem);

	// 겹쳤던 WorldItem 액터를 제거합니다.
	void RemoveOverlappedWorldItem(class AWorldItemActor* worldItem);

	// 거리를 기준으로 가까운 순서대로 WorldItem들을 정렬합니다
	void SortWorldItemByDistance();

	// 가장 가까운 월드 아이템의 상호작용 위젯을 표시합니다
	void ShowNearestWorldItemInteractionWidget();

	// 아이템을 장착합니다.
	// worlItemInfo : 장착 가능한 월드 아이템 정보를 전달합니다
	void EquipItem(struct FWorldItemInfo* worldItemInfo);

	void Fire();

public:
	void OnFirePressed();
	void OnFireReleased();

	void OnGetItemPressed();
	
	void OnJumpInput();

	void OnHorizontalInput(float axis);
	void OnVerticalInput(float axis);

	FORCEINLINE FIntVector GetInputAxisRaw() const
	{
		return InputAxisRaw;
	}

	FORCEINLINE float GetCurrentSpeed() const
	{
		return CurrentSpeed;
	}

	FORCEINLINE EWorldItemType GetEquippedItemType() const
	{
		return EquippedItemType;
	}

	bool IsEquipped() const;

};
