// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enum/ColorType.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef JUMPPROJECT_ColorType_generated_h
#error "ColorType.generated.h already included, missing '#pragma once' in ColorType.h"
#endif
#define JUMPPROJECT_ColorType_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h


#define FOREACH_ENUM_ECOLORTYPE(op) \
	op(EColorType::Color_Red) \
	op(EColorType::Color_Yellow) \
	op(EColorType::Color_Sky) \
	op(EColorType::Color_Magenta) \
	op(EColorType::Color_White) \
	op(EColorType::Color_Orange) \
	op(EColorType::Color_Green) 

enum class EColorType : uint8;
template<> struct TIsUEnumClass<EColorType> { enum { Value = true }; };
template<> JUMPPROJECT_API UEnum* StaticEnum<EColorType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
