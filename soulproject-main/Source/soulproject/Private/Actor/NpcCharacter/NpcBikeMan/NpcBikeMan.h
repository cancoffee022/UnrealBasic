// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/NpcCharacter/NpcCharacter.h"
#include "NpcBikeMan.generated.h"

/**
 * 
 */
UCLASS()
class ANpcBikeMan : public ANpcCharacter
{
	GENERATED_BODY()

public:
	ANpcBikeMan();

	virtual bool OnInteractionStarted(FOnInterationFinishSignature onInteractionFinished) override;
	
};
