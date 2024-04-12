// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UHorizontalBox* HorizontalBox_InteractionItem;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlock_ItemName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlock_BulletRemain;

protected:
	virtual void NativeConstruct() override;

public:
	// 상호작용 위젯을 표시합니다
	// itemName : 표시할 아이템 이름을 전달합니다
	void ShowInteractionItem(FText itemName);

	// 상호작용 위젯을 숨깁니다
	void HideInteractionWidget();

	void UpdateBulletRemainText(int remain, int max);
	
};
