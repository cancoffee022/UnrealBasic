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
	// TSubclassOf<T> : Uclass 에 대한 안전성을 보장하는 형식
	// T 형식과 T 형식의 파생 클래스들에 대한 정보들만 담을 수 있는 형식

public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;
};
