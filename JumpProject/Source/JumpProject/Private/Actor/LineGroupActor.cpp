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
}

// Called every frame
void ALineGroupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALineGroupActor::InitializeLineObjects(UStaticMesh* lineObjectStaticMesh,
	UMaterial* lineObjectMaterial)
{
	// ��Ʈ ������Ʈ�� �����մϴ�
	LineGroupRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT_COMPONENT"));
	SetRootComponent(LineGroupRootComponent);

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
		newLineObject->SetRelativeLocation(FVector::RightVector * FGameConstants::GetLineObjectTerm() * i);

		// ������ Static Mesh Component�� �迭�� �߰��մϴ�.
		LineObjects.Add(newLineObject);
	}
}

