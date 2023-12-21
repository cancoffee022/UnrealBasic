// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enum/GameTurn.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TICTACTOE_GameTurn_generated_h
#error "GameTurn.generated.h already included, missing '#pragma once' in GameTurn.h"
#endif
#define TICTACTOE_GameTurn_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h


#define FOREACH_ENUM_EGAMETURN(op) \
	op(EGameTurn::Turn_Player) \
	op(EGameTurn::Turn_AI) 

enum class EGameTurn : uint8;
template<> struct TIsUEnumClass<EGameTurn> { enum { Value = true }; };
template<> TICTACTOE_API UEnum* StaticEnum<EGameTurn>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
