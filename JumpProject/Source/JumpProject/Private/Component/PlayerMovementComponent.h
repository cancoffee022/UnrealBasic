
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	// 캐릭터에 적용된 선수
	FVector Velocity;

	// 중력에 곱해질 승수
	UPROPERTY(EditAnywhere, Category="Custom Gravity",meta = (AllowPrivateAccess = "true"))
	float GravityMultiplier;
	// private 필드를 에디터에서 편집 가능하도록 하려면
	// 먼저 AllowPrivateAccess = "true"를 통해 Private 필드에 대한 접근을 허용해야하며
	// EditAnywhere을 통해 이 필드에 대한 값을 설정할 수 있도록 지정해야 합니다.

	// 점프 힘
	UPROPERTY(EditAnywhere, Category="Custom Gravity", meta = (AllowPrivateAccess = "true"))
	float JumpPower;

	// 최대 높이
	// 캐릭터의 위치가 이 높이를 초과하는 경우 점프가 불가능해진다
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

	// 점프 시킵니다
	void Jump();

private:
	// 중력을 적용시킵니다
	void ApplyGravity();

	// 다음 위치의 충돌체를 확인합니다
	void CheckCollision();
	
	// 속도에 따라 캐릭터를 이동시킵니다
	void Move();
		
};
