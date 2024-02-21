
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

	// ���̵��� ���۵Ǵ� �Ÿ�
	float fadeStartDistance = 30.f;

	// ������ �������� �Ÿ�
	float fadedDistance = 50.f;

	// �÷��̾�� Npc ������ �Ÿ�
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
