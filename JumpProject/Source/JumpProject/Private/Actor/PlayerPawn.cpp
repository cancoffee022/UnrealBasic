// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerPawn.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Sphere Static Mesh 에셋을 로드합니다
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SPHERE(
		TEXT("/Script/Engine.StaticMesh'/Game/Resources/Sphere.Sphere'"));

	// Material 에셋을 로드합니다
	static ConstructorHelpers::FObjectFinder<UMaterial> MASTER_COLOR(
		TEXT("/Script/Engine.Material'/Game/Resources/Master_Color.Master_Color'"));

	// StaticMeshComponent를 생성합니다
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PLAYER_MESH"));
	// CreateDefaultSubobject<T>(stringData) : T 형식의 하위 객체를 생성합니다.
	// 무조건 생성자에서만 사용가능 합니다.
	// stringData : 이 객체를 참조하는 변수가 없다며느 해당이름으로 표시됩니다.
	// 이 객체를 참조하는 변수가 있다면, 변수의 이름으로 표시됩니다.

	// PlayerMesh 컴포넌트를 이 액터의 루트 컴포넌트로 지정합니다.
	SetRootComponent(PlayerMesh);
	// 루트 컴포넌트 : 액터를 대표하는 컴포넌트
	// 단 하나만 존재할 수 있습니다.
	
	// 크기를 0.2배로 설정합니다
	PlayerMesh->SetRelativeScale3D(FVector(.2f, .2f, .2f));

	// 로드에 성공 했다면
	if (SM_SPHERE.Succeeded())
	{
		// 로드한 StaticMesh 에셋을 StaticMeshComponent에 설정합니다.
		PlayerMesh->SetStaticMesh(SM_SPHERE.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SM_SPHERE not loaded!"));
	}

	if (MASTER_COLOR.Succeeded())
		PlayerMesh->SetMaterial(0, MASTER_COLOR.Object);
	else
		UE_LOG(LogTemp, Error, TEXT("MASTER_COLOR not loaded!"));
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


