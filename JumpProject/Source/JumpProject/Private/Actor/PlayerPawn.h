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

	// �÷��̾� Mesh�� ǥ���ϱ� ���� ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* PlayerMesh;
	// VisibleAnyWhere : ������Ƽ â�� ��������, ������ �� ������ ��Ÿ���ϴ�.

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
