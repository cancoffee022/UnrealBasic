// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/NpcCharacter/NpcBikeMan/NpcBikeMan.h"

ANpcBikeMan::ANpcBikeMan()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/NPC/Rider/Ch20_nonPBR.Ch20_nonPBR'"));
	if (SM_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_BODY.Object);
	}

}
