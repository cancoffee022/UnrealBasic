// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	TSubclassOf<class UGameMapWidget> GameMapWidgetClass;
	// TSubclassOf<T> : Uclass �� ���� �������� �����ϴ� ����
	// T ���İ� T ������ �Ļ� Ŭ�����鿡 ���� �����鸸 ���� �� �ִ� ����

public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;
};
