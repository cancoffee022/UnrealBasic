#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	// ����� �Է��� Vector2�� ��Ÿ���ϴ�
	FVector2D InputVector;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAcess = "true"))
	class UPlayerCharacterMovementComponent* PlayerCharacterMovementComponent;

public:
	// Sets default values for this character's properties
	AGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �Է� �� ���� ��ȯ�մϴ�
	FORCEINLINE FVector2D GetInputVector() const { return InputVector; }

	void UpdateInputVector(FVector2D inputVector);

};
