// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldItemType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWorldItemType: uint8
{
	RANGE_WEAPON_START = 0,

	Weapon_Pistol = 1	UMETA(Displayname = "Pistol"),
	Weapon_Rifle = 2	UMETA(Displayname = "Rifle"),
	Weapon_Shotgun = 3	UMETA(Displayname = "Shotgun"),
	
	RANGE_WEAPON_END = 4,

	//RANGE_WEAPON_START,
	//
	//Consume_HealHp,
	// Consume_HealStemina,
	// 
	//RANGE_WEAPON_END,
};
