// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"

#include "Actor/MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	// ��θ� 
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN(
		TEXT("/ Script / Engine.Blueprint'/Game/Blueprints/Actor/BP_Pawn.BP_Pawn_C'"));
	if (BP_PAWN.Succeeded())
	{
		DefaultPawnClass = BP_PAWN.Class;
	}


	// ���� PlayerController Ŭ������ �����մϴ�
	PlayerControllerClass = AMyPlayerController::StaticClass();
	// Class::StaticClass() : ������ Ŭ������ UClass* �� ����ϴ�.

	// �⺻������ ���� Pawn Ŭ������ �����մϴ�
	//DefaultPawnClass = ;
}
