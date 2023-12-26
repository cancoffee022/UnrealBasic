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
	// 루트 컴포넌트를 생성합니다
	LineGroupRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT_COMPONENT"));
	SetRootComponent(LineGroupRootComponent);

	for (int32 i = 0; i < FGameConstants::NUMBER_OF_LINEOBJECT; ++i)
	{

		// Static Mesh Component를 생성합니다
		UStaticMeshComponent* newLineObject = CreateDefaultSubobject<UStaticMeshComponent>(
			*(FString("LINEOBJ") + FString::FromInt(i)));

		// 생성된 StaticMeshComponent의 부모 컴포너트를 지정합니다.
		newLineObject->SetupAttachment(LineGroupRootComponent);

		if (lineObjectStaticMesh != nullptr)
		{
			// 라인 오브젝트의 Static Mesh에셋을 설정하는 구문
			newLineObject->SetStaticMesh(lineObjectStaticMesh);
		}
		
		if (lineObjectMaterial != nullptr)
		{
			// 라인 오브젝트의 메테리얼을 설정하는 구문
			newLineObject->SetMaterial(0, lineObjectMaterial);
		}

		// 라인 오브젝트의 StaticMesh 에셋을 설정하는 구문
		newLineObject->SetStaticMesh(lineObjectStaticMesh);

		// 라인 오브젝트의 크기를 설정하는 구문
		newLineObject->SetRelativeScale3D(FGameConstants::GetLineObjectSize());

		// 라인 오브젝트를 일렬로 나열시키는 구문
		newLineObject->SetRelativeLocation(FVector::RightVector * FGameConstants::GetLineObjectTerm() * i);

		// 생성된 Static Mesh Component를 배열에 추가합니다.
		LineObjects.Add(newLineObject);
	}
}

