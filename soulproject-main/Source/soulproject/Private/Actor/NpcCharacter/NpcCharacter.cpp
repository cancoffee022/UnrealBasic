#include "Actor/NpcCharacter/NpcCharacter.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Structure/NpcData/NpcData.h"

#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"

#include "Widget/NpcWidget/NpcWidget.h"

#include "Kismet/GameplayStatics.h"
// Sets default values
ANpcCharacter::ANpcCharacter()
{
	//static ConstructorHelpers::FObjectFinder<UDataTable> DT_NPCDATA(
	//	TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_NpcData.DT_NpcData'"));

	//if (DT_NPCDATA.Succeeded())
	//{
	//	DT_NpcData = DT_NPCDATA.Object;
	//}

	//static ConstructorHelpers::FClassFinder<UNpcWidget> WIDGETBP_NPC(
	//	TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/NpcWidget/WidgetBP_Npc.WidgetBP_Npc_C'"));

	//// 위젯 컴포넌트 생성
	//NpcWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WIDGET_COMP"));
	//NpcWidgetComponent->SetupAttachment(GetRootComponent());
	//NpcWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	//NpcWidgetComponent->SetRelativeLocation(
	//	FVector::UpVector * GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * .5f);

	//if (WIDGETBP_NPC.Succeeded())
	//{
	//	NpcWidgetComponent->SetWidgetClass(WIDGETBP_NPC.Class);
	//}

 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANpcCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeNpcData();

	// Npc 위젯 초기화
	UNpcWidget* npcWidget = Cast<UNpcWidget>(NpcWidgetComponent->GetUserWidgetObject());

	// 플레이어 캐릭터 액터
	AActor* gameCharacter = UGameplayStatics::GetActorOfClass(GetWorld(), AGameCharacter::StaticClass());
	
	npcWidget->InitializeNpcWidget(this, gameCharacter, NpcData->Name);
}

void ANpcCharacter::InitializeNpcData()
{
	if (NpcCode.IsNone())
	{
		NpcData = nullptr;
		UE_LOG(LogTemp, Warning, TEXT("NpcCode is none"));
		return;
	}

	// TODO
	//NpcData = 

}

// Called every frame
void ANpcCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANpcCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

