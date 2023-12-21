// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JumpProject/Private/PlayerController/GamePlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePlayerController() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	JUMPPROJECT_API UClass* Z_Construct_UClass_AGamePlayerController();
	JUMPPROJECT_API UClass* Z_Construct_UClass_AGamePlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_JumpProject();
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGamePlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_JumpProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PlayerController/GamePlayerController.h" },
		{ "ModuleRelativePath", "Private/PlayerController/GamePlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGamePlayerController_Statics::NewProp_CameraComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xab\xef\xbf\xbd\xde\xb6\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/PlayerController/GamePlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xab\xef\xbf\xbd\xde\xb6\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb4\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGamePlayerController_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGamePlayerController, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::NewProp_CameraComponent_MetaData), Z_Construct_UClass_AGamePlayerController_Statics::NewProp_CameraComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGamePlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGamePlayerController_Statics::NewProp_CameraComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGamePlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGamePlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGamePlayerController_Statics::ClassParams = {
		&AGamePlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGamePlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::PropPointers),
		0,
		0x008002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGamePlayerController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGamePlayerController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AGamePlayerController()
	{
		if (!Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton, Z_Construct_UClass_AGamePlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGamePlayerController.OuterSingleton;
	}
	template<> JUMPPROJECT_API UClass* StaticClass<AGamePlayerController>()
	{
		return AGamePlayerController::StaticClass();
	}
	AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGamePlayerController);
	AGamePlayerController::~AGamePlayerController() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_PlayerController_GamePlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_PlayerController_GamePlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGamePlayerController, AGamePlayerController::StaticClass, TEXT("AGamePlayerController"), &Z_Registration_Info_UClass_AGamePlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGamePlayerController), 3654529210U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_PlayerController_GamePlayerController_h_162075844(TEXT("/Script/JumpProject"),
		Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_PlayerController_GamePlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_PlayerController_GamePlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
