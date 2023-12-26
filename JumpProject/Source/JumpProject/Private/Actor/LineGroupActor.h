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

	TArray<class UStaticMeshComponent*> LineObjects;
	
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

};
