
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// ĳ���Ϳ� ����� ����
	FVector Velocity;

	// �߷¿� ������ �¼�
	UPROPERTY(EditAnywhere, Category="Custom Gravity",meta = (AllowPrivateAccess = "true"))
	float GravityMultiplier;
	// private �ʵ带 �����Ϳ��� ���� �����ϵ��� �Ϸ���
	// ���� AllowPrivateAccess = "true"�� ���� Private �ʵ忡 ���� ������ ����ؾ��ϸ�
	// EditAnywhere�� ���� �� �ʵ忡 ���� ���� ������ �� �ֵ��� �����ؾ� �մϴ�.

	// ���� ��
	UPROPERTY(EditAnywhere, Category="Custom Gravity", meta = (AllowPrivateAccess = "true"))
	float JumpPower;

	// �ִ� ����
	// ĳ������ ��ġ�� �� ���̸� �ʰ��ϴ� ��� ������ �Ұ���������
	UPROPERTY(EditAnywhere,Category="Jump", meta = (AllowPrivateAccess = "true"))
	float MaxHeight;

public:	
	// Sets default values for this component's properties
	UPlayerMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ���� ��ŵ�ϴ�
	void Jump();

private:
	// �߷��� �����ŵ�ϴ�
	void ApplyGravity();

	// ���� ��ġ�� �浹ü�� Ȯ���մϴ�
	void CheckCollision();
	
	// �ӵ��� ���� ĳ���͸� �̵���ŵ�ϴ�
	void Move();
		
};
