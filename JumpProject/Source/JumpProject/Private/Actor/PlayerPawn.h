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

	// �÷��̾� �̵��� ����ϴ� ������Ʈ
	UPROPERTY(VisibleAnywhere)
	class UPlayerMovementComponent* PlayerMovement;

	// �Ķ���͸� ������ �� �ִ� ����� ���̳��� ���͸��� ��ü�� ��Ÿ���ϴ�
	class UMaterialInstanceDynamic* PlayerMaterial;

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// ���� ����� ȣ��Ǵ� �Լ��Դϴ�.
	// passedLineGroupActor : ����� ���� �׷� ���Ͱ� ���޵˴ϴ�
	void OnLinePassed(class ALineGroupActor* passedLineGroupActor);

	// ĳ���Ϳ��� ������ ������ŵ�ϴ�.
	// newColor : ���� ��ų ������ �����մϴ�
	void SetColor(FLinearColor newColor);

public:
	// �����Ǵ� ��� ȣ��˴ϴ�.
	void OnJump();

};
