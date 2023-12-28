// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JumpProject/Private/Structure/ColorData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeColorData() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	JUMPPROJECT_API UEnum* Z_Construct_UEnum_JumpProject_EColorType();
	JUMPPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColorData();
	UPackage* Z_Construct_UPackage__Script_JumpProject();
// End Cross Module References

static_assert(std::is_polymorphic<FColorData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FColorData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ColorData;
class UScriptStruct* FColorData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ColorData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ColorData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FColorData, (UObject*)Z_Construct_UPackage__Script_JumpProject(), TEXT("ColorData"));
	}
	return Z_Registration_Info_UScriptStruct_ColorData.OuterSingleton;
}
template<> JUMPPROJECT_API UScriptStruct* StaticStruct<FColorData>()
{
	return FColorData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FColorData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_ColorType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ColorType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ColorType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FColorData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Private/Structure/ColorData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FColorData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FColorData>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType_MetaData[] = {
		{ "Category", "ColorData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Structure/ColorData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType = { "ColorType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FColorData, ColorType), Z_Construct_UEnum_JumpProject_EColorType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType_MetaData), Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType_MetaData) }; // 4109839191
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FColorData_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "ColorData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Private/Structure/ColorData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FColorData_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FColorData, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorData_Statics::NewProp_Color_MetaData), Z_Construct_UScriptStruct_FColorData_Statics::NewProp_Color_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FColorData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FColorData_Statics::NewProp_ColorType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FColorData_Statics::NewProp_Color,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FColorData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_JumpProject,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"ColorData",
		Z_Construct_UScriptStruct_FColorData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorData_Statics::PropPointers),
		sizeof(FColorData),
		alignof(FColorData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FColorData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FColorData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FColorData()
	{
		if (!Z_Registration_Info_UScriptStruct_ColorData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ColorData.InnerSingleton, Z_Construct_UScriptStruct_FColorData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ColorData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Structure_ColorData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Structure_ColorData_h_Statics::ScriptStructInfo[] = {
		{ FColorData::StaticStruct, Z_Construct_UScriptStruct_FColorData_Statics::NewStructOps, TEXT("ColorData"), &Z_Registration_Info_UScriptStruct_ColorData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FColorData), 2965719000U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Structure_ColorData_h_1362340363(TEXT("/Script/JumpProject"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Structure_ColorData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Structure_ColorData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
