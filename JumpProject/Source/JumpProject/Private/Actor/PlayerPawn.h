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

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
