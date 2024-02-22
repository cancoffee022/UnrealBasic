#include "Actor/NpcCharacter/NpcCharacter.h"
#include "Actor/GameCharacter/GameCharacter.h"

#include "Actor/PlayerController/GamePlayerController.h"

#include "Structure/NpcData/NpcData.h"

#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"

#include "Component/InteractableAreaComponent/InteractableAreaComponent.h"

#include "Widget/NpcWidget/NpcWidget.h"
#include "Widget/GameWidget/GameWidget.h"
#include "Widget/NpcDialogWidget/NpcDialogWidget.h"

#include "Kismet/GameplayStatics.h"
// Sets default values
ANpcCharacter::ANpcCharacter()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_NPCDATA(
		TEXT("/Script/Engine.DataTable'/Game/Resources/DataTable/DT_NpcData.DT_NpcData'"));

	if (DT_NPCDATA.Succeeded())
	{
		DT_NpcData = DT_NPCDATA.Object;
	}

	static ConstructorHelpers::FClassFinder<UNpcWidget> WIDGETBP_NPC(
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Widget/NpcWidget/WidgetBP_Npc.WidgetBP_Npc_C'"));

	// 상호 작용 가능한 영역 컴포넌트
	InteractableAreaComponent =
		CreateDefaultSubobject<UInteractableAreaComponent>(TEXT("INTERACTABLE_AREA_COMPONENT"));
	InteractableAreaComponent->SetupAttachment(GetRootComponent());
	InteractableAreaComponent->SetSphereRadius(300.f);

	// 위젯 컴포넌트 생성
	NpcWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WIDGET_COMP"));
	NpcWidgetComponent->SetupAttachment(GetRootComponent());
	NpcWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	NpcWidgetComponent->SetRelativeLocation(
		FVector::UpVector * GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * .5f);

	if (WIDGETBP_NPC.Succeeded())
	{
		NpcWidgetComponent->SetWidgetClass(WIDGETBP_NPC.Class);
	}

 
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

	FString contextString;
	NpcData = DT_NpcData->FindRow<FNpcData>(NpcCode, contextString);

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

void ANpcCharacter::OnInteractionStarted()
{
	// 첫 번째 플레이어 컨트롤러 (플레이어의 컨트롤러)를 얻습니다.
	AGamePlayerController* playerController = Cast<AGamePlayerController>(
		GetWorld()->GetFirstPlayerController());

	// 표시할 위젯을 생성합니다.
	NpcDialogWidget = CreateWidget<UNpcDialogWidget>(playerController, NpcData->DialogWidgetClass);

	// Npc Dialog 위젯을 띄웁니다.
	playerController->GetGameWidget()->FloatingWidgetAdditive(NpcDialogWidget);

	// 위젯 초기화
	NpcDialogWidget->InitializeNpcDialogWidget(NpcData);

	// 입력 모드를 UI 모드로 전환합니다.
	playerController->SetInputMode(FInputModeUIOnly());

	// 커서를 표시합니다.
	playerController->bShowMouseCursor = true;

}


