#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GenericTeamAgentInterface.h"
#include "Enum/CharacterTeam.h"

#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter,
	public IGenericTeamAgentInterface
{
	GENERATED_BODY()

private :
	// 피해를 입었을때 재생시킬 애님 몽타주
	UPROPERTY()
	class UAnimMontage* HitAnimMontage;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UZoomableSpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UPlayerCharacterMovementComponent* PlayerCharacterMovementComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UPlayerCharacterAnimController* PlayerCharacterAnimController;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UPlayerCharacterAttackComponent* AttackComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* WeaponMesh;

	FGenericTeamId Team;

public:
	AGameCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnDamaged(
		AActor* damageActor,
		float damage,
		const class UDamageType* damageType,
		class AController* instigatedBy,
		AActor* damageCauser);

public:	
	virtual void SetupPlayerInputComponent(
		class UInputComponent* PlayerInputComponent) override;

	void OnHorizontalInput(float axis);
	void OnVerticalInput(float axis);
	void OnZoomInput(float axis);
	void OnJumpInput();
	void OnAttackInput();

	FORCEINLINE class UPlayerCharacterAttackComponent* GetAttackComponent() const
	{
		return AttackComponent;
	}

	FORCEINLINE virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override
	{
		Team = TeamID;
	}

	FORCEINLINE virtual FGenericTeamId GetGenericTeamId() const override
	{
		return Team;
	}

};
