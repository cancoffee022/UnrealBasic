// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Component/PlayerMovementComponent.h"
#include "LineGroupActor.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Sphere Static Mesh ������ �ε��մϴ�
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SPHERE(
		TEXT("/Script/Engine.StaticMesh'/Game/Resources/Sphere.Sphere'"));

	// Material ������ �ε��մϴ�
	static ConstructorHelpers::FObjectFinder<UMaterial> MASTER_COLOR(
		TEXT("/Script/Engine.Material'/Game/Resources/Master_Color.Master_Color'"));

	// StaticMeshComponent�� �����մϴ�
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PLAYER_MESH"));
	// CreateDefaultSubobject<T>(stringData) : T ������ ���� ��ü�� �����մϴ�.
	// ������ �����ڿ����� ��밡�� �մϴ�.
	// stringData : �� ��ü�� �����ϴ� ������ ���ٸ�� �ش��̸����� ǥ�õ˴ϴ�.
	// �� ��ü�� �����ϴ� ������ �ִٸ�, ������ �̸����� ǥ�õ˴ϴ�.

	PlayerMovement = CreateDefaultSubobject<UPlayerMovementComponent>(TEXT("PLAYER_MOVEMENT"));

	// PlayerMesh ������Ʈ�� �� ������ ��Ʈ ������Ʈ�� �����մϴ�.
	SetRootComponent(PlayerMesh);
	// ��Ʈ ������Ʈ : ���͸� ��ǥ�ϴ� ������Ʈ
	// �� �ϳ��� ������ �� �ֽ��ϴ�.
	
	// ũ�⸦ 0.2��� �����մϴ�
	PlayerMesh->SetRelativeScale3D(FVector(.2f, .2f, .2f));

	// �ε忡 ���� �ߴٸ�
	if (SM_SPHERE.Succeeded())
	{
		// �ε��� StaticMesh ������ StaticMeshComponent�� �����մϴ�.
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
	
	// ���� ��� �̺�Ʈ�� ���ε� �մϴ�.
	FOnLinePassedEventSignature linePassedEvent; 
	linePassedEvent.BindUObject(this, &ThisClass::OnLinePassed);
	PlayerMovement->SetLinePassedEvent(linePassedEvent);

	// �Ķ���͸� �����ϱ� ���� ������� ���͸����� ���� �����մϴ�
	UMaterialInstanceDynamic* copiedMaterial =UMaterialInstanceDynamic::Create(PlayerMesh->GetMaterial(0), this);

	// �ٸ� �Լ����� ����� �� �ֵ��� �����մϴ�
	PlayerMaterial = copiedMaterial;

	// ���� ������ ���͸����� �����մϴ�
	PlayerMesh->SetMaterial(0, copiedMaterial);
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

void APlayerPawn::OnLinePassed(ALineGroupActor* passedLineGroupActor)
{
	// ������ �����մϴ�
	FLinearColor nextColor = passedLineGroupActor->GetNextColor();
	SetColor(nextColor);

	UE_LOG(LogTemp, Warning, TEXT("Passed"));
}

void APlayerPawn::SetColor(FLinearColor newColor)
{
	PlayerMaterial->SetVectorParameterValue(TEXT("_Color"), newColor);
}

void APlayerPawn::OnJump()
{
	PlayerMovement->Jump();
}