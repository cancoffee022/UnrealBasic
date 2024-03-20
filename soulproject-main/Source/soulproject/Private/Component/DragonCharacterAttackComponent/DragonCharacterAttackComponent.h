#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DragonCharacterAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDragonCharacterAttackComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool IsBreathFire;

	UPROPERTY()
	bool IsClawAttack;

public:	
	UDragonCharacterAttackComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void StartBreathFire();
	void OnBreathFireFinished();

	void StartClawAttack();
	void FinishClawAttack();
		
public:
	FORCEINLINE bool GetBreathFireState() const
	{
		return IsBreathFire;
	}

	FORCEINLINE bool GetClawAttackState() const
	{
		return IsClawAttack;
	}

};