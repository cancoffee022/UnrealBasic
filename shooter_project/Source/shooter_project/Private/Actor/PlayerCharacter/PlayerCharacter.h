// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHOOTER_PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
// SpringArm ������Ʈ �߰�
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* PistolMesh;
	
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* RifleMesh;
	
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* ShotgunMesh;

	// �Է� �� ���� ��Ÿ���ϴ�
	UPROPERTY(VisibleAnywhere, Replicated)
	FIntVector InputAxisRaw;

	UPROPERTY(VisibleAnywhere, Replicated)
	float CurrentSpeed;

private:
	// ��ģ World Item ���͵��� ��Ÿ���ϴ�
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

	// ��ģ WorldItem ���͸� �߰��մϴ�.
	void AddOverlappedWorldItem(class AWorldItemActor* worldItem);

	// ���ƴ� WorldItem ���͸� �����մϴ�.
	void RemoveOverlappedWorldItem(class AWorldItemActor* worldItem);

	// �Ÿ��� �������� ����� ������� WorldItem���� �����մϴ�
	void SortWorldItemByDistance();

	// ���� ����� ���� �������� ��ȣ�ۿ� ������ ǥ���մϴ�
	void ShowNearestWorldItemInteractionWidget();

	// �������� �����մϴ�.
	// worlItemInfo : ���� ������ ���� ������ ������ �����մϴ�
	void EquipItem(struct FWorldItemInfo* worldItemInfo);

public:
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

};
