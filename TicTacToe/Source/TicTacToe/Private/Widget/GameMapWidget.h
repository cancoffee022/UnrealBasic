// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMapWidget.generated.h"


/**
 * 
 */
UCLASS()
class UGameMapWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	// �ɺ� TextBlock ��ü���� �����ص� �迭
	TArray<class UTextBlock*> SimbolTexts;
	/// TArray<Type> : �𸮾󿡼� �����ϴ� �����̳�
	/// TSet : ���� ������ �����Ǹ�, �ߺ� ������� �ʽ��ϴ�
	/// TMap : Ű�� ���� �Բ� ����Ǹ�, Ű�� �ߺ� ������� �ʽ��ϴ�

protected:
	virtual void NativeConstruct() override;

private:
	// ���Ǵ� ��� ������ ã���ϴ�
	void FindAllWidgets();

public:
	// AI �ɺ��� XY��ġ�� �����մϴ�.
	void SetAISimbol(int x, int y);
};
