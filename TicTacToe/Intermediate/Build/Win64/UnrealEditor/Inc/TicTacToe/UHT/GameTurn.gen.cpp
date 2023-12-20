// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TicTacToe/Private/Enum/GameTurn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameTurn() {}
// Cross Module References
	TICTACTOE_API UEnum* Z_Construct_UEnum_TicTacToe_EGameTurn();
	UPackage* Z_Construct_UPackage__Script_TicTacToe();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameTurn;
	static UEnum* EGameTurn_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EGameTurn.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EGameTurn.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TicTacToe_EGameTurn, (UObject*)Z_Construct_UPackage__Script_TicTacToe(), TEXT("EGameTurn"));
		}
		return Z_Registration_Info_UEnum_EGameTurn.OuterSingleton;
	}
	template<> TICTACTOE_API UEnum* StaticEnum<EGameTurn>()
	{
		return EGameTurn_StaticEnum();
	}
	struct Z_Construct_UEnum_TicTacToe_EGameTurn_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enumerators[] = {
		{ "EGameTurn::Turn_Player", (int64)EGameTurn::Turn_Player },
		{ "EGameTurn::Turn_AI", (int64)EGameTurn::Turn_AI },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n// BlueprintType : \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb6\xef\xbf\xbd\xef\xbf\xbd, BlueprintType \xef\xbf\xbd\xdb\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xb2\xef\xbf\xbd\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd uint8 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xbe\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n" },
#endif
		{ "ModuleRelativePath", "Private/Enum/GameTurn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n// BlueprintType : \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb6\xef\xbf\xbd\xef\xbf\xbd, BlueprintType \xef\xbf\xbd\xdb\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xb2\xef\xbf\xbd\n// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd uint8 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xbe\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd." },
#endif
		{ "Turn_AI.DisplayName", "AI \xef\xbf\xbd\xef\xbf\xbd" },
		{ "Turn_AI.Name", "EGameTurn::Turn_AI" },
		{ "Turn_Player.DisplayName", "\xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd" },
		{ "Turn_Player.Name", "EGameTurn::Turn_Player" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_TicTacToe,
		nullptr,
		"EGameTurn",
		"EGameTurn",
		Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enum_MetaDataParams), Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_TicTacToe_EGameTurn()
	{
		if (!Z_Registration_Info_UEnum_EGameTurn.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameTurn.InnerSingleton, Z_Construct_UEnum_TicTacToe_EGameTurn_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EGameTurn.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h_Statics::EnumInfo[] = {
		{ EGameTurn_StaticEnum, TEXT("EGameTurn"), &Z_Registration_Info_UEnum_EGameTurn, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2125911299U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h_2448536418(TEXT("/Script/TicTacToe"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Enum_GameTurn_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
