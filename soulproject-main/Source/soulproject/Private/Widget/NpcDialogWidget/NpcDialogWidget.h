// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NpcDialogWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNpcDialogWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	class UTextBlock* Text_Name;
	
	UPROPERTY()
	class UTextBlock* Text_Dialog;

protected:
	virtual void NativeConstruct() override;
	
public:
	void InitializeNpcDialogWidget(struct FNpcData* npcData);

}; 
