// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/LineGroupActor.h"
#include "Components/StaticMeshComponent.h"
#include "../GameConstants.h"

// Sets default values
ALineGroupActor::ALineGroupActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_CUBE(
		TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	static ConstructorHelpers::FObjectFinder<UMaterial> MASTER_COLOR(
		TEXT("/ Script / Engine.Material'/Game/Resources/Master_Color.Master_Color'"));

	UStaticMesh* cubeStaticMesh = nullptr;
	UMaterial* lineObjectMaterial = nullptr;
	if (SM_CUBE.Succeeded()) cubeStaticMesh = SM_CUBE.Object;
	else UE_LOG(LogTemp, Error, TEXT("SM_CUBE is not loaded!"));

	if(MASTER_COLOR.Succeeded()) lineObjectMaterial = MASTER_COLOR.Object;
	else UE_LOG(LogTemp, Error, TEXT("MASTER_COLOR is not loaded!"));
	PrimaryActorTick.bCanEverTick = true;

	InitializeLineObjects(cubeStaticMesh, lineObjectMaterial);
}

// Called when the game starts or when spawned
void ALineGroupActor::BeginPlay()
{
	Super::BeginPlay();

	for (UStaticMeshComponent* lineObj : LineObjects)
	{
		UMaterialInterface* lineObjMaterial = lineObj->GetMaterial(0);

		// ���͸��� �Ķ���͵��� �ٸ� ���� ������ �ϱ����Ͽ� ���͸����� ���� �����մϴ�
		UMaterialInstanceDynamic* materialDynamicInstance = UMaterialInstanceDynamic::Create(lineObjMaterial, this);

		materialDynamicInstance->SetVectorParameterValue(
			TEXT("_Color"),
			FLinearColor(
				FMath::FRandRange(0.1f, 1.0f), // R
				FMath::FRandRange(0.1f, 1.0f), // G
				FMath::FRandRange(0.1f, 1.0f), // B
				1.0f));						   // A
		lineObj->SetMaterial(0, materialDynamicInstance);
	}
}

// Called every frame
void ALineGroupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���� �׷��� �̵���ŵ�ϴ�.
	MoveLineGroup(DeltaTime);
	
	// ���� ������Ʈ�� ��ũ�Ѹ� ��ŵ�ϴ�
	ScrollingLineObject(DeltaTime);
}

void ALineGroupActor::InitializeLineObjects(UStaticMesh* lineObjectStaticMesh,
	UMaterial* lineObjectMaterial)
{
	// ��Ʈ ������Ʈ�� �����մϴ�
	LineGroupRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT_COMPONENT"));
	SetRootComponent(LineGroupRootComponent);

	// ���� ������Ʈ ũ�� Y
	float lineObjectTerm = FGameConstants::GetLineObjectTerm();

	// ���Ǵ� ���� ������Ʈ ����
	int32 numberOfLineObject = FGameConstants::NUMBER_OF_LINEOBJECT;

	// ���� ������Ʈ ��ġ ���� ��ġ
	FVector lineObjectStartLocation =
		((lineObjectTerm * numberOfLineObject * .5f) + (lineObjectTerm * .5f)) * FVector::LeftVector;

	for (int32 i = 0; i < FGameConstants::NUMBER_OF_LINEOBJECT; ++i)
	{
		// Static Mesh Component�� �����մϴ�
		UStaticMeshComponent* newLineObject = CreateDefaultSubobject<UStaticMeshComponent>(
			*(FString("LINEOBJ") + FString::FromInt(i)));

		// ������ StaticMeshComponent�� �θ� ������Ʈ�� �����մϴ�.
		newLineObject->SetupAttachment(LineGroupRootComponent);

		if (lineObjectStaticMesh != nullptr)
		{
			// ���� ������Ʈ�� Static Mesh������ �����ϴ� ����
			newLineObject->SetStaticMesh(lineObjectStaticMesh);
		}
		
		if (lineObjectMaterial != nullptr)
		{
			// ���� ������Ʈ�� ���׸����� �����ϴ� ����
			newLineObject->SetMaterial(0, lineObjectMaterial);
		}

		// ���� ������Ʈ�� StaticMesh ������ �����ϴ� ����
		newLineObject->SetStaticMesh(lineObjectStaticMesh);

		// ���� ������Ʈ�� ũ�⸦ �����ϴ� ����
		newLineObject->SetRelativeScale3D(FGameConstants::GetLineObjectSize());

		// ���� ������Ʈ�� �Ϸķ� ������Ű�� ����
		newLineObject->SetRelativeLocation(
			FVector::RightVector * FGameConstants::GetLineObjectTerm() * i + lineObjectStartLocation);

		// ������ Static Mesh Component�� �迭�� �߰��մϴ�.
		LineObjects.Add(newLineObject);
	}
}

void ALineGroupActor::MoveLineGroup(float deltaTime)
{
	// ���� �׷��� �̵���ų ��ǥ��ġ�� ����մϴ�
	float lineGroupTerm = FGameConstants::GetLineGroupTerm();
	

	// ���� �׷��� �̵���ų ��ǥ ��ġ�� ����մϴ�
	FVector newLocation = GetActorLocation();
	newLocation.Z = (LineGroupIndex * lineGroupTerm) + lineGroupTerm * -1;

	// ���� ���� �Լ�
	// - ������ ���� �־����� �� �� ���̿� ��ġ�� ���� �����ϱ� ���Ͽ� ���� �Ÿ��� ���� ���������� ����ϴ� ���
	// A	: ������
	// B	: ����
	// Alpha: 
	newLocation.Z = FMath::Lerp(GetActorLocation().Z,
		newLocation.Z,
		deltaTime * FGameConstants::GetLineGroupMoveSpeed());

	// ������ ��ġ�� �����մϴ�
	SetActorLocation(newLocation);
}

void ALineGroupActor::ScrollingLineObject(float deltaTime)
{
	// ���� ������Ʈ ��
	float lineObjectTerm = FGameConstants::GetLineObjectTerm();

	// �ִ� ��ũ�Ѹ� �Ÿ�
	float maxScrollingDistance = 
		(LineObjects.Num() * lineObjectTerm) + (lineObjectTerm * .5f) - (LineObjects.Num() * lineObjectTerm * .5f);

	for (UStaticMeshComponent* lineObj : LineObjects)
	{
		// ���� ������Ʈ�� ��� ��ġ�� ����ϴ�
		FVector lineLocation = lineObj->GetRelativeLocation();

		// ���� ������ �̵���ŵ�ϴ�.
		lineLocation.Y += FGameConstants::GetLineObjectScrollingSpeed() * deltaTime;

		// ���� ������Ʈ ���� ��ũ�Ѹ� ����
		// �ִ� ��ũ�Ѹ� �Ÿ��� �ʰ��ߴٸ�
		if (lineLocation.Y > maxScrollingDistance) 
			lineLocation.Y -= (LineObjects.Num() * lineObjectTerm);

		lineObj->SetRelativeLocation(lineLocation);
	}
}

void ALineGroupActor::InitializeLineGroup(int32 index)
{
	// ���� �ε����� �����մϴ�
	SetLineGroupIndex(index);
}
