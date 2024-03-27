// Copyright Epic Games, Inc. All Rights Reserved.

#include "shooter_projectGameMode.h"
#include "shooter_projectCharacter.h"
#include "UObject/ConstructorHelpers.h"

Ashooter_projectGameMode::Ashooter_projectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
