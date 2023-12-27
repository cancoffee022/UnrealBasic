// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LineGroupActor.generated.h"

UCLASS()
class ALineGroupActor : public AActor
{
	GENERATED_BODY()

protected:
	// ������Ʈ ���� ������ �����ϱ� ���� ���Ǵ� �� �� ������Ʈ�Դϴ�.
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* LineGroupRootComponent;

	// ���� �׷��� �̷�� ���ε��� ��Ÿ���� StaticMeshComponent
	TArray<class UStaticMeshComponent*> LineObjects;

	// ���� �׷� �ε����� ��Ÿ���ϴ�
	// ���� ���� ��ġ�� ���� �׷��� 0������ ���˴ϴ�.
	// �� �ε����� ���� ���� �׷��� ��ġ�Ǵ� ��ġ�� �����˴ϴ�.
	int32 LineGroupIndex;
	
public:	
	// Sets default values for this actor's properties
	ALineGroupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	// ���� ������Ʈ�� �����մϴ�
	void InitializeLineObjects(
		class UStaticMesh* lineObjectStaticMesh,
		class UMaterial* lineObjectMaterial);

	// ���� �׷��� �ε��� ���� ���� �̵���ŵ�ϴ�
	// deltaTime : ������ ���� ���ݽð��� �����մϴ�.
	void MoveLineGroup(float DeltaTime);

	// ���� ������Ʈ�� ��ũ�Ѹ� ��ŵ�ϴ�
	// deltaTime : ������ ���� ���ݽð��� �����մϴ�.
	void ScrollingLineObject(float deltaTime);

public:
	// ���� �׷��� �ʱ�ȭ�մϴ�.
	// index : ������ų ���α׷� �ε����� �����մϴ�
	void InitializeLineGroup(int32 index);

public:
	// ���� �׷� �ε����� �����մϴ�
	void SetLineGroupIndex(int32 index) 
	{
		LineGroupIndex = index;
	}

};
