// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/GameCharacter/GameCharacter.h"

#include "../../Component/PlayerCharacterMovementComponent/PlayerCharacterMovementComponent.h"
#include "../../Component/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CHARACTER_MESH(
		TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast'"));

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 추가
	SpringArmComponent = CreateDefaultSubobject<UZoomableSpringArmComponent>(
			TEXT("SPRING_ARM"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	PlayerCharacterMovementComponent = 
		CreateDefaultSubobject<UPlayerCharacterMovementComponent>(
			TEXT("MOVEMENT_COMPONENT"));

	// SpringArm 컴포넌트를 루트 컴포넌트에 추가합니다.
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(GetRootComponent());

	// 컨트롤러 Yaw 회전 사용 X
	bUseControllerRotationYaw = false;

	// 무브먼트 방향으로 회전 사용
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 회전 속도 설정
	GetCharacterMovement()->RotationRate = FRotator(0.f, 450.f, 0.f);

	// 스프링암의 회전을 컨트롤러의 회전으로 일치시킵니다
	SpringArmComponent->bUsePawnControlRotation = true;

	if (SK_CHARACTER_MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CHARACTER_MESH.Object);
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::DownVector * 88.0f,
			FRotator(0.f, -90.f, 0.f));
	}
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameCharacter::OnHorizontalInput(float axis)
{
	PlayerCharacterMovementComponent->HorizontalMove(axis);
}

void AGameCharacter::OnVerticalInput(float axis)
{
	PlayerCharacterMovementComponent->VerticalMove(axis);
}
