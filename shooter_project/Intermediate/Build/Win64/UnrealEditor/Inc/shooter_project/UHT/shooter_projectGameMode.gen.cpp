// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "shooter_project/shooter_projectGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeshooter_projectGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_Ashooter_projectGameMode();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_Ashooter_projectGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_shooter_project();
// End Cross Module References
	void Ashooter_projectGameMode::StaticRegisterNativesAshooter_projectGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(Ashooter_projectGameMode);
	UClass* Z_Construct_UClass_Ashooter_projectGameMode_NoRegister()
	{
		return Ashooter_projectGameMode::StaticClass();
	}
	struct Z_Construct_UClass_Ashooter_projectGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Ashooter_projectGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_shooter_project,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Ashooter_projectGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Ashooter_projectGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "shooter_projectGameMode.h" },
		{ "ModuleRelativePath", "shooter_projectGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Ashooter_projectGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Ashooter_projectGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_Ashooter_projectGameMode_Statics::ClassParams = {
		&Ashooter_projectGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Ashooter_projectGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_Ashooter_projectGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_Ashooter_projectGameMode()
	{
		if (!Z_Registration_Info_UClass_Ashooter_projectGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Ashooter_projectGameMode.OuterSingleton, Z_Construct_UClass_Ashooter_projectGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_Ashooter_projectGameMode.OuterSingleton;
	}
	template<> SHOOTER_PROJECT_API UClass* StaticClass<Ashooter_projectGameMode>()
	{
		return Ashooter_projectGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(Ashooter_projectGameMode);
	Ashooter_projectGameMode::~Ashooter_projectGameMode() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_shooter_projectGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_shooter_projectGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_Ashooter_projectGameMode, Ashooter_projectGameMode::StaticClass, TEXT("Ashooter_projectGameMode"), &Z_Registration_Info_UClass_Ashooter_projectGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Ashooter_projectGameMode), 3153900080U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_shooter_projectGameMode_h_3112114561(TEXT("/Script/shooter_project"),
		Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_shooter_projectGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_shooter_projectGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
