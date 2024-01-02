// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Enum/ColorType.h"
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

private:
	// ��� ������ ���� ������Ʈ �ε����� ��Ÿ���ϴ�.
	int32 PassableLineObjectIndex;

	// ĳ���͸� �����ų ���� Ÿ��
	EColorType PassableColorType;

	// ������� ��� ĳ���Ϳ��� ������ų ���� Ÿ��
	EColorType NextColorType;

	// ������� ��� ĳ���Ϳ��� ������ų ����
	FLinearColor NextColor;
	
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
	// lineObjectStaticMesh : ���� ������Ʈ�� ���� StaticMesh ������ �����մϴ�
	// lineObjectMaterial : ���� ������Ʈ�� ���� Material ������ �����մϴ�.
	void InitializeLineObjects(
		class UStaticMesh* lineObjectStaticMesh,
		class UMaterial* lineObjectMaterial);

	// ���� ������Ʈ ������ �����մϴ�
	// colors : ��� ������ ������� �����մϴ�.
	// colorTypes : ���� ���� Ÿ�Ե��� ������� �����մϴ�.
	void SetLineObjectColors(TArray<FLinearColor> colors, TArray<EColorType> colorTypes);


	// ���� �׷��� �ε��� ���� ���� �̵���ŵ�ϴ�
	// deltaTime : ������ ���� ���ݽð��� �����մϴ�.
	void MoveLineGroup(float DeltaTime);

	// ���� ������Ʈ�� ��ũ�Ѹ� ��ŵ�ϴ�
	// deltaTime : ������ ���� ���ݽð��� �����մϴ�.
	void ScrollingLineObject(float deltaTime);

public:
	// ���� �׷��� �ʱ�ȭ �մϴ�
	// index : ������Ų ���� �׷� �ε����� ������
	// colors : ��� ������ ������� �����մϴ�.
	// colorTypes : ���� ���� Ÿ�Ե��� ������� �����մϴ�.
	// lineObjectStaticMesh : ���� ������Ʈ�� ���� StaticMesh ������ �����մϴ�
	// lineObjectMaterial : ���� ������Ʈ�� ���� Material ������ �����մϴ�.
	void InitializeLineGroup(
		int32 index,
		TArray<FLinearColor> colors,
		TArray<EColorType> colorTypes,
		EColorType passableColor,
		EColorType nextColor);

	// ������ StaticMeshComponent �� ��� ������ LineObject���� Ȯ���մϴ�.
	// lineObject : ��� ���� ���θ� Ȯ���� StaticMeshComponent�� �����մϴ�.
	bool IsPassableLineObject(class UStaticMeshComponent* lineObject);

	// �ش� ���� �׷��� ��� �Ǿ��� ��� ȣ��˴ϴ�
	// out_NextColor : ��¿� �Ű������̸�, �÷��̾�� ��������ų ���� ������ ��ȯ�մϴ�.
	void OnLineGroupPassed(FLinearColor& out_NextColor);

public:
	// ���� �׷� �ε����� �����մϴ�
	FORCEINLINE void SetLineGroupIndex(int32 index) 
	{
		LineGroupIndex = index;
	}

	// ���������� ��ȯ�մϴ�
	FORCEINLINE FLinearColor GetNextColor() const
	{
		return NextColor;
	}

};
