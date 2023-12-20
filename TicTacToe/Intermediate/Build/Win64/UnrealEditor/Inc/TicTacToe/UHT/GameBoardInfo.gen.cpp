// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TicTacToe/Private/Struct/GameBoardInfo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameBoardInfo() {}
// Cross Module References
	TICTACTOE_API UScriptStruct* Z_Construct_UScriptStruct_FGameBoardInfo();
	UPackage* Z_Construct_UPackage__Script_TicTacToe();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GameBoardInfo;
class UScriptStruct* FGameBoardInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GameBoardInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GameBoardInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameBoardInfo, (UObject*)Z_Construct_UPackage__Script_TicTacToe(), TEXT("GameBoardInfo"));
	}
	return Z_Registration_Info_UScriptStruct_GameBoardInfo.OuterSingleton;
}
template<> TICTACTOE_API UScriptStruct* StaticStruct<FGameBoardInfo>()
{
	return FGameBoardInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGameBoardInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ArrayIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ArrayIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_X;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Simbol_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Simbol;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameBoardInfo_Statics::Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Private/Struct/GameBoardInfo.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameBoardInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_ArrayIndex_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xe8\xbf\xad \xef\xbf\xbd\xce\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Struct/GameBoardInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xe8\xbf\xad \xef\xbf\xbd\xce\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_ArrayIndex = { "ArrayIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameBoardInfo, ArrayIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_ArrayIndex_MetaData), Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_ArrayIndex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_X_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xad \xef\xbf\xbd\xce\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Struct/GameBoardInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcd\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xad \xef\xbf\xbd\xce\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameBoardInfo, X), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_X_MetaData), Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_X_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Y_MetaData[] = {
		{ "ModuleRelativePath", "Private/Struct/GameBoardInfo.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameBoardInfo, Y), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Y_MetaData), Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Y_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Simbol_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc9\xba\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Struct/GameBoardInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc9\xba\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Simbol = { "Simbol", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameBoardInfo, Simbol), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Simbol_MetaData), Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Simbol_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameBoardInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_ArrayIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_X,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Y,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewProp_Simbol,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameBoardInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TicTacToe,
		nullptr,
		&NewStructOps,
		"GameBoardInfo",
		Z_Construct_UScriptStruct_FGameBoardInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::PropPointers),
		sizeof(FGameBoardInfo),
		alignof(FGameBoardInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameBoardInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameBoardInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FGameBoardInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_GameBoardInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GameBoardInfo.InnerSingleton, Z_Construct_UScriptStruct_FGameBoardInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GameBoardInfo.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Struct_GameBoardInfo_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Struct_GameBoardInfo_h_Statics::ScriptStructInfo[] = {
		{ FGameBoardInfo::StaticStruct, Z_Construct_UScriptStruct_FGameBoardInfo_Statics::NewStructOps, TEXT("GameBoardInfo"), &Z_Registration_Info_UScriptStruct_GameBoardInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameBoardInfo), 3068817285U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Struct_GameBoardInfo_h_2733117381(TEXT("/Script/TicTacToe"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Struct_GameBoardInfo_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Struct_GameBoardInfo_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
