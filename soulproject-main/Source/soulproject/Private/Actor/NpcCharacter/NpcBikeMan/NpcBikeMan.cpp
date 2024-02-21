// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/NpcCharacter/NpcBikeMan/NpcBikeMan.h"

#include "AnimInstance/NpcCharacter/NpcAnimInstance.h"


ANpcBikeMan::ANpcBikeMan()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_BODY(
		TEXT("/Script/Engine.SkeletalMesh'/Game/Resources/NPC/Rider/Ch20_nonPBR.Ch20_nonPBR'"));

	static ConstructorHelpers::FClassFinder<UNpcAnimInstance> ANIMBP_NPC(
		TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/AnimInstance/AnimBp_BikeMan.AnimBp_BikeMan_C'"));


	if (SM_BODY.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_BODY.Object);
	}

	if (ANIMBP_NPC.Succeeded())
	{
		GetMesh()->SetAnimClass(ANIMBP_NPC.Class);
	}

}
