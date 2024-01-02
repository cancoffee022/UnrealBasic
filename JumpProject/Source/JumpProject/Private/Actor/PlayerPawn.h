// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class APlayerPawn : public APawn
{
	GENERATED_BODY()

private:

	// 플레이어 Mesh를 표시하기 위한 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* PlayerMesh;
	// VisibleAnyWhere : 프로퍼티 창에 보이지만, 편집할 수 없음을 나타냅니다.

	// 플레이어 이동을 담당하는 컴포넌트
	UPROPERTY(VisibleAnywhere)
	class UPlayerMovementComponent* PlayerMovement;

	// 파라미터를 변경할 수 있는 복사된 다이나믹 매터리얼 객체를 나타냅니다
	class UMaterialInstanceDynamic* PlayerMaterial;

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 라인 통과시 호출되는 함수입니다.
	// passedLineGroupActor : 통과한 라인 그룹 액터가 전달됩니다
	void OnLinePassed(class ALineGroupActor* passedLineGroupActor);

	// 캐릭터에게 색상을 설정시킵니다.
	// newColor : 설정 시킬 색상을 전달합니다
	void SetColor(FLinearColor newColor);

public:
	// 점프되는 경우 호출됩니다.
	void OnJump();

};
