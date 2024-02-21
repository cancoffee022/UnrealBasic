
#include "Widget/NpcWidget/NpcWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/Actor.h"

void UNpcWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Text_Name = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Name")));
}

void UNpcWidget::InitializeNpcWidget(AActor* ownerCharacter, AActor* gameCharacterActor, FText npcName)
{
	OwnerCharacter = ownerCharacter;
	GameCharacter = gameCharacterActor;
	Text_Name->SetText(npcName);
	UE_LOG(LogTemp, Warning, TEXT("npcName = %s"), *npcName.ToString());
}

void UNpcWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// 페이딩이 시작되는 거리
	float fadeStartDistance = 30.f;

	// 완전히 숨겨지는 거리
	float fadedDistance = 50.f;

	// 플레이어와 Npc 사이의 거리
	float distance = FVector::Distance(OwnerCharacter->GetActorLocation(), GameCharacter->GetActorLocation());

	FLinearColor color = Text_Name->GetColorAndOpacity().GetSpecifiedColor();
	//color.A = 1.f - (distance / (maxDistance - fadeStartDistance));

	float Alpha = 1.f;
	if (distance < fadeStartDistance)
		Alpha = 1.f;
	else if (distance > fadedDistance)
		Alpha = 0;
	else
	{
		Alpha = 1.f - ((distance - fadeStartDistance) / (fadedDistance - fadeStartDistance));
	}

	Text_Name->SetColorAndOpacity(color);
}
