// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMapWidget.generated.h"

// �÷��̾� �ɺ��� ���ŵ� ��츦 ��Ÿ���� ���� �븮�� ����
// int32 x: �ɺ��� ������ X ��ġ
// int32 y: �ɺ��� ������ Y ��ġ
DECLARE_DELEGATE_TwoParams(OnPlayerSimbolUpdated_Signature, int32 /* x */, int32 /* y */)

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

	// �÷��̾� �ɺ��� ���ŵǾ��� ��� �߻��ϴ� �̺�Ʈ�Դϴ�.
	OnPlayerSimbolUpdated_Signature OnPlayerSimbolUpdated;

protected:
	virtual void NativeConstruct() override;

private:
	// ���Ǵ� ��� ������ ã���ϴ�
	void FindAllWidgets();

	// ��ư �̺�Ʈ�� ���ε� �մϴ�
	void BindButtonEvents();

	UFUNCTION()
	void OnGameBoardClicked(int32 x, int32 y);

	UFUNCTION()
	void OnGameBoardClicked00();
	UFUNCTION()
	void OnGameBoardClicked01();
	UFUNCTION()
	void OnGameBoardClicked02();
	UFUNCTION()
	void OnGameBoardClicked10();
	UFUNCTION()
	void OnGameBoardClicked11();
	UFUNCTION()
	void OnGameBoardClicked12();
	UFUNCTION()
	void OnGameBoardClicked20();
	UFUNCTION()
	void OnGameBoardClicked21();
	UFUNCTION()
	void OnGameBoardClicked22();

public:
	// �÷��̾� �ɺ��� ���ŵǾ��� ��� �߻���ų �̺�Ʈ�� �����մϴ�
	FORCEINLINE void SetPlayerSimbolUpdatedEvent(
		OnPlayerSimbolUpdated_Signature onPlayerSimbolUpdated)
	{
		OnPlayerSimbolUpdated = onPlayerSimbolUpdated;
	}

	// AI �ɺ��� XY��ġ�� �����մϴ�.
	void SetAISimbol(int y, int x);
};
