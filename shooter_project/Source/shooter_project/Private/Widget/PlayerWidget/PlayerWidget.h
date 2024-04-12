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
	// ��ȣ�ۿ� ������ ǥ���մϴ�
	// itemName : ǥ���� ������ �̸��� �����մϴ�
	void ShowInteractionItem(FText itemName);

	// ��ȣ�ۿ� ������ ����ϴ�
	void HideInteractionWidget();

	void UpdateBulletRemainText(int remain, int max);
	
};
