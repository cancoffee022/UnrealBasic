#include "Actor/WorldItem/WorldItemActor.h"
#include "Struct/WorldItemInfo.h"

#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"

#include "../shooter_project.h"

AWorldItemActor::AWorldItemActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// 월드 아이템 정보를 담는 데이터 테이블 에셋 로드
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_WORLDITEMINFO(
		TEXT("/Script/Engine.DataTable'/Game/DataTable/DT_WorldItemInfo.DT_WorldItemInfo'"));
	if (DT_WORLDITEMINFO.Succeeded()) DT_WorldItemInfo = DT_WORLDITEMINFO.Object;

	// 기본적으로 아이템 위치에 표시할 StaticMesh 에셋 로드
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_DEFITEMVISUAL(
		TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));

	// 루트 컴포넌트 추가
	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>("DEF_ROOT");
	SetRootComponent(DefaultRootComponent);

	// 아이템 상호작용 가능 영역 컴포넌트 추가
	InteractableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ITRCT_COMP"));
	InteractableArea->SetupAttachment(GetRootComponent());

	// 아이템 SkeletalMesh 컴포넌트 생성
	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_MESH"));
	ItemSkeletalMesh->SetupAttachment(GetRootComponent());
	ItemSkeletalMesh->SetCollisionProfileName(TEXT("NoCollision"));

	// 아이템 StaticMesh 컴포넌트 생성
	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ST_MESH"));
	ItemStaticMesh->SetupAttachment(GetRootComponent());
	if (SM_DEFITEMVISUAL.Succeeded()) ItemStaticMesh->SetStaticMesh(SM_DEFITEMVISUAL.Object);
	ItemStaticMesh->SetCollisionProfileName(TEXT("NoCollision"));

}

void AWorldItemActor::BeginPlay()
{
	Super::BeginPlay();

	InitializeWorldItem();
	
	// World Item Tag 추가
	Tags.Add(TAG_WORLDITEM);
}

void AWorldItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWorldItemActor::InitializeWorldItem()
{
	// ItemCode 에 해당하는 아이템 정보를 얻습니다.
	FString contextString;
	ThisWorldItemInfo = DT_WorldItemInfo->FindRow<FWorldItemInfo>(ItemCode, contextString);

	// 아이템 코드를 찾을 수 없는 경우
	if (ThisWorldItemInfo == nullptr)
	{
		UE_LOG(LogTemp, Error,
			TEXT("아이템 코드에 해당하는 아이템 정보를 찾을 수 없습니다. (itemCode : %s)"), 
			*ItemCode.ToString());
		return;
	}


	// StaticMesh 스케일 초기화
	ItemStaticMesh->SetRelativeScale3D(FVector::One());

	// StaticMesh Visual 초기화
	ItemStaticMesh->SetStaticMesh(nullptr);

	// SketletalMesh 설정
	ItemSkeletalMesh->SetSkeletalMesh(ThisWorldItemInfo->ItemMesh);
}

