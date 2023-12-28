// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JumpProject/Private/Enum/ColorType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColorType() {}
// Cross Module References
	JUMPPROJECT_API UEnum* Z_Construct_UEnum_JumpProject_EColorType();
	UPackage* Z_Construct_UPackage__Script_JumpProject();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EColorType;
	static UEnum* EColorType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EColorType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EColorType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JumpProject_EColorType, (UObject*)Z_Construct_UPackage__Script_JumpProject(), TEXT("EColorType"));
		}
		return Z_Registration_Info_UEnum_EColorType.OuterSingleton;
	}
	template<> JUMPPROJECT_API UEnum* StaticEnum<EColorType>()
	{
		return EColorType_StaticEnum();
	}
	struct Z_Construct_UEnum_JumpProject_EColorType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_JumpProject_EColorType_Statics::Enumerators[] = {
		{ "EColorType::Color_Red", (int64)EColorType::Color_Red },
		{ "EColorType::Color_Yellow", (int64)EColorType::Color_Yellow },
		{ "EColorType::Color_Sky", (int64)EColorType::Color_Sky },
		{ "EColorType::Color_Magenta", (int64)EColorType::Color_Magenta },
		{ "EColorType::Color_White", (int64)EColorType::Color_White },
		{ "EColorType::Color_Orange", (int64)EColorType::Color_Orange },
		{ "EColorType::Color_Green", (int64)EColorType::Color_Green },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_JumpProject_EColorType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Color_Green.DisplayName", "Green" },
		{ "Color_Green.Name", "EColorType::Color_Green" },
		{ "Color_Magenta.DisplayName", "Magenta" },
		{ "Color_Magenta.Name", "EColorType::Color_Magenta" },
		{ "Color_Orange.DisplayName", "Orange" },
		{ "Color_Orange.Name", "EColorType::Color_Orange" },
		{ "Color_Red.DisplayName", "Red" },
		{ "Color_Red.Name", "EColorType::Color_Red" },
		{ "Color_Sky.DisplayName", "Sky" },
		{ "Color_Sky.Name", "EColorType::Color_Sky" },
		{ "Color_White.DisplayName", "White" },
		{ "Color_White.Name", "EColorType::Color_White" },
		{ "Color_Yellow.DisplayName", "Yellow" },
		{ "Color_Yellow.Name", "EColorType::Color_Yellow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa2\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n// - \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd(enum class)\n// - UENUM(BlueprintType) \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n// - .generated.h \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n// - underling type \xef\xbf\xbd\xef\xbf\xbd uint8 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n// - \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\xb8\xef\xbf\xbd \xef\xbf\xbd\xd5\xbf\xef\xbf\xbd E \xef\xbf\xbd\xdb\xbc\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Enum/ColorType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa2\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd(enum class)\n- UENUM(BlueprintType) \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n- .generated.h \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n- underling type \xef\xbf\xbd\xef\xbf\xbd uint8 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\xb8\xef\xbf\xbd \xef\xbf\xbd\xd5\xbf\xef\xbf\xbd E \xef\xbf\xbd\xdb\xbc\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JumpProject_EColorType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_JumpProject,
		nullptr,
		"EColorType",
		"EColorType",
		Z_Construct_UEnum_JumpProject_EColorType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_JumpProject_EColorType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JumpProject_EColorType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JumpProject_EColorType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_JumpProject_EColorType()
	{
		if (!Z_Registration_Info_UEnum_EColorType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EColorType.InnerSingleton, Z_Construct_UEnum_JumpProject_EColorType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EColorType.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h_Statics::EnumInfo[] = {
		{ EColorType_StaticEnum, TEXT("EColorType"), &Z_Registration_Info_UEnum_EColorType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4109839191U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h_887780964(TEXT("/Script/JumpProject"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Enum_ColorType_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
