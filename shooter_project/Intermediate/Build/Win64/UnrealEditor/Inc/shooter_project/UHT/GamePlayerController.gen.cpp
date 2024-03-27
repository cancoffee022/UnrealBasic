// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "shooter_project/Private/Actor/PlayerController/GamePlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePlayerController() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_AGamePlayerController();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_AGamePlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_shooter_project();
// End Cross Module References
	void AGamePlayerController::StaticRegisterNativesAGamePlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGamePlayerController);
	UClass* Z_Construct_UClass_AGamePlayerController_NoRegister()
	{
		return AGamePlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AGamePlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGamePlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_shooter_project,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Actor/PlayerController/GamePlayerController.h" },
		{ "ModuleRelativePath", "Private/Actor/PlayerController/GamePlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGamePlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGamePlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGamePlayerController_Statics::ClassParams = {
		&AGamePlayerController::StaticClass,
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
		0x008002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AGamePlayerController()
	{
		if (!Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton, Z_Construct_UClass_AGamePlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton;
	}
	template<> SHOOTER_PROJECT_API UClass* StaticClass<AGamePlayerController>()
	{
		return AGamePlayerController::StaticClass();
	}
	AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGamePlayerController);
	AGamePlayerController::~AGamePlayerController() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_Actor_PlayerController_GamePlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_Actor_PlayerController_GamePlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGamePlayerController, AGamePlayerController::StaticClass, TEXT("AGamePlayerController"), &Z_Registration_Info_UClass_AGamePlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGamePlayerController), 837952279U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_Actor_PlayerController_GamePlayerController_h_3482868214(TEXT("/Script/shooter_project"),
		Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_Actor_PlayerController_GamePlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_Actor_PlayerController_GamePlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
