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

	// 라인 그룹을 이동시킵니다.
	MoveLineGroup(DeltaTime);
	
	// 라인 오브젝트를 스크롤링 시킵니다
	ScrollingLineObject(DeltaTime);
}

void ALineGroupActor::InitializeLineObjects(UStaticMesh* lineObjectStaticMesh,
	UMaterial* lineObjectMaterial)
{
	// 루트 컴포넌트를 생성합니다
	LineGroupRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT_COMPONENT"));
	SetRootComponent(LineGroupRootComponent);

	// 라인 오브젝트 크기 Y
	float lineObjectTerm = FGameConstants::GetLineObjectTerm();

	// 사용되는 라인 오브젝트 개수
	int32 numberOfLineObject = FGameConstants::NUMBER_OF_LINEOBJECT;

	// 라인 오븢젝트 배치 시작 위치
	FVector lineObjectStartLocation =
		((lineObjectTerm * numberOfLineObject * .5f) - (lineObjectTerm * .5f)) * FVector::LeftVector;

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
		newLineObject->SetRelativeLocation(
			FVector::RightVector * FGameConstants::GetLineObjectTerm() * i + lineObjectStartLocation);

		// 생성된 Static Mesh Component를 배열에 추가합니다.
		LineObjects.Add(newLineObject);
	}
}

void ALineGroupActor::SetLineObjectColors(
	TArray<FLinearColor> colors,
	TArray<EColorType> colorTypes)
{
	for (int32 i = 0; i < LineObjects.Num(); ++i)
	{
		// i번째 LineObject를 얻습니다.
		UStaticMeshComponent* lineObject = LineObjects[i];

		// 라인 오브젝트의 색상을 설정합니다
		EColorType colorType = colorTypes[i];
		FLinearColor lineColor = colors[(int32)colorType];

		// 통과 가능한 색상 타입이라면 
		if (PassableColorType == colorType)
		{
			//통과 가능 LineObject 인덱스를 설정합니다
			PassableLineObjectIndex = i;

			// 통과 가능한 색상을 저장합니다
			NextColor = lineColor;
		}

		// 라인 오브젝트에 색상을 설정합니다
		// 매터리얼 파라미터들이 다른 값을 갖도록 하기위하여 매터리얼을 복사 생성합니다
		UMaterialInstanceDynamic* materialDynamicInstance =
			UMaterialInstanceDynamic::Create(lineObject->GetMaterial(0), this);

		// 매터리얼 파라미터를 변경합니다
		materialDynamicInstance->SetVectorParameterValue(
			TEXT("_Color"), lineColor);

		lineObject->SetMaterial(0, materialDynamicInstance);
	}
}

void ALineGroupActor::MoveLineGroup(float deltaTime)
{
	// 라인 그룹을 이동시킬 목표위치를 계산합니다
	float lineGroupTerm = FGameConstants::GetLineGroupTerm();
	

	// 라인 그룹을 이동시킬 목표 위치를 계산합니다
	FVector newLocation = GetActorLocation();
	newLocation.Z = (LineGroupIndex * lineGroupTerm) + lineGroupTerm * -1;

	// 선형 보간 함수
	// - 끝점의 값이 주어졌을 때 그 사이에 위치한 값을 추정하기 위하여 직선 거리에 따라 선형적으로 계산하는 방법
	// A	: 시작점
	// B	: 끝점
	// Alpha: 
	newLocation.Z = FMath::Lerp(GetActorLocation().Z,
		newLocation.Z,
		deltaTime * FGameConstants::GetLineGroupMoveSpeed());

	// 액터의 위치를 설정합니다
	SetActorLocation(newLocation);
}

void ALineGroupActor::ScrollingLineObject(float deltaTime)
{
	// 라인 오브젝트 텀
	float lineObjectTerm = FGameConstants::GetLineObjectTerm();

	// 최대 스크롤링 거리
	float maxScrollingDistance = 
		(LineObjects.Num() * lineObjectTerm) + (lineObjectTerm * .5f) - (LineObjects.Num() * lineObjectTerm * .5f);

	for (UStaticMeshComponent* lineObj : LineObjects)
	{
		// 라인 오브젝트의 상대 위치를 얻습니다
		FVector lineLocation = lineObj->GetRelativeLocation();

		// 오른 쪽으로 이동시킵니다.
		lineLocation.Y += FGameConstants::GetLineObjectScrollingSpeed() * deltaTime;

		// 라인 오브젝트 무한 스크롤링 구문
		// 최대 스크롤링 거리를 초과했다면
		if (lineLocation.Y > maxScrollingDistance) 
			lineLocation.Y -= (LineObjects.Num() * lineObjectTerm);

		lineObj->SetRelativeLocation(lineLocation);
	}
}

void ALineGroupActor::InitializeLineGroup(
	int32 index,
	TArray<FLinearColor> colors,
	TArray<EColorType> colorTypes,
	EColorType passableColor,
	EColorType nextColor)
{
	PassableColorType = passableColor;
	NextColorType = nextColor;
	// 라인 인덱스를 설정합니다
	SetLineGroupIndex(index);

	// 라인 오브젝트 색상들을 모두 설정합니다
	SetLineObjectColors(colors, colorTypes);
}

bool ALineGroupActor::IsPassableLineObject(UStaticMeshComponent* lineObject)
{
	// 라인 오브젝트에 해당하는 요소 인덱스를 얻습니다
	int32 index = LineObjects.Find(lineObject);

	// 통과 가능여부를 반환합니다
	return index == PassableLineObjectIndex;
}

void ALineGroupActor::OnLineGroupPassed(FLinearColor& out_NextColor)
{
}
