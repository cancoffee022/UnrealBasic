// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"

#include "Actor/MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	// 경로를 
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN(
		TEXT("/ Script / Engine.Blueprint'/Game/Blueprints/Actor/BP_Pawn.BP_Pawn_C'"));
	if (BP_PAWN.Succeeded())
	{
		DefaultPawnClass = BP_PAWN.Class;
	}


	// 사용될 PlayerController 클래스를 지정합니다
	PlayerControllerClass = AMyPlayerController::StaticClass();
	// Class::StaticClass() : 지정한 클래스의 UClass* 를 얻습니다.

	// 기본적으로 사용될 Pawn 클래스를 지정합니다
	//DefaultPawnClass = ;
}
