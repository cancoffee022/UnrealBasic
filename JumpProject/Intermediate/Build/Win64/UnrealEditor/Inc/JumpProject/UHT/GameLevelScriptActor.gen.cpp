// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JumpProject/Private/LevelScriptActor/GameLevelScriptActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameLevelScriptActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ALevelScriptActor();
	JUMPPROJECT_API UClass* Z_Construct_UClass_AGameLevelScriptActor();
	JUMPPROJECT_API UClass* Z_Construct_UClass_AGameLevelScriptActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_JumpProject();
// End Cross Module References
	void AGameLevelScriptActor::StaticRegisterNativesAGameLevelScriptActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGameLevelScriptActor);
	UClass* Z_Construct_UClass_AGameLevelScriptActor_NoRegister()
	{
		return AGameLevelScriptActor::StaticClass();
	}
	struct Z_Construct_UClass_AGameLevelScriptActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialLineGroupCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InitialLineGroupCount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameLevelScriptActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ALevelScriptActor,
		(UObject* (*)())Z_Construct_UPackage__Script_JumpProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameLevelScriptActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameLevelScriptActor_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "LevelScriptActor/GameLevelScriptActor.h" },
		{ "ModuleRelativePath", "Private/LevelScriptActor/GameLevelScriptActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameLevelScriptActor_Statics::NewProp_InitialLineGroupCount_MetaData[] = {
		{ "Category", "GameLevelScriptActor" },
		{ "ModuleRelativePath", "Private/LevelScriptActor/GameLevelScriptActor.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGameLevelScriptActor_Statics::NewProp_InitialLineGroupCount = { "InitialLineGroupCount", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGameLevelScriptActor, InitialLineGroupCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameLevelScriptActor_Statics::NewProp_InitialLineGroupCount_MetaData), Z_Construct_UClass_AGameLevelScriptActor_Statics::NewProp_InitialLineGroupCount_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameLevelScriptActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameLevelScriptActor_Statics::NewProp_InitialLineGroupCount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameLevelScriptActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameLevelScriptActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGameLevelScriptActor_Statics::ClassParams = {
		&AGameLevelScriptActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameLevelScriptActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGameLevelScriptActor_Statics::PropPointers),
		0,
		0x008002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGameLevelScriptActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AGameLevelScriptActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGameLevelScriptActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AGameLevelScriptActor()
	{
		if (!Z_Registration_Info_UClass_AGameLevelScriptActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGameLevelScriptActor.OuterSingleton, Z_Construct_UClass_AGameLevelScriptActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGameLevelScriptActor.OuterSingleton;
	}
	template<> JUMPPROJECT_API UClass* StaticClass<AGameLevelScriptActor>()
	{
		return AGameLevelScriptActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameLevelScriptActor);
	AGameLevelScriptActor::~AGameLevelScriptActor() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_LevelScriptActor_GameLevelScriptActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_LevelScriptActor_GameLevelScriptActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGameLevelScriptActor, AGameLevelScriptActor::StaticClass, TEXT("AGameLevelScriptActor"), &Z_Registration_Info_UClass_AGameLevelScriptActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGameLevelScriptActor), 3452136599U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_LevelScriptActor_GameLevelScriptActor_h_1673170501(TEXT("/Script/JumpProject"),
		Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_LevelScriptActor_GameLevelScriptActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_LevelScriptActor_GameLevelScriptActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
