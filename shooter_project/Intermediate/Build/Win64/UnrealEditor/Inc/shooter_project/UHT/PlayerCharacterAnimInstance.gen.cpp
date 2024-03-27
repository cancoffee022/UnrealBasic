// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "shooter_project/Private/AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerCharacterAnimInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_UPlayerCharacterAnimInstance();
	SHOOTER_PROJECT_API UClass* Z_Construct_UClass_UPlayerCharacterAnimInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_shooter_project();
// End Cross Module References
	void UPlayerCharacterAnimInstance::StaticRegisterNativesUPlayerCharacterAnimInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerCharacterAnimInstance);
	UClass* Z_Construct_UClass_UPlayerCharacterAnimInstance_NoRegister()
	{
		return UPlayerCharacterAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsMove_MetaData[];
#endif
		static void NewProp_IsMove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsMove;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_shooter_project,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h" },
		{ "ModuleRelativePath", "Private/AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove_MetaData[] = {
		{ "Category", "PlayerCharacterAnimInstance" },
		{ "ModuleRelativePath", "Private/AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove_SetBit(void* Obj)
	{
		((UPlayerCharacterAnimInstance*)Obj)->IsMove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove = { "IsMove", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPlayerCharacterAnimInstance), &Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove_MetaData), Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "PlayerCharacterAnimInstance" },
		{ "ModuleRelativePath", "Private/AnimInstance/PlayerCharacterAnimInstance/PlayerCharacterAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerCharacterAnimInstance, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_Speed_MetaData), Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_Speed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_IsMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::NewProp_Speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerCharacterAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::ClassParams = {
		&UPlayerCharacterAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::PropPointers),
		0,
		0x008000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPlayerCharacterAnimInstance()
	{
		if (!Z_Registration_Info_UClass_UPlayerCharacterAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerCharacterAnimInstance.OuterSingleton, Z_Construct_UClass_UPlayerCharacterAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPlayerCharacterAnimInstance.OuterSingleton;
	}
	template<> SHOOTER_PROJECT_API UClass* StaticClass<UPlayerCharacterAnimInstance>()
	{
		return UPlayerCharacterAnimInstance::StaticClass();
	}
	UPlayerCharacterAnimInstance::UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerCharacterAnimInstance);
	UPlayerCharacterAnimInstance::~UPlayerCharacterAnimInstance() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_AnimInstance_PlayerCharacterAnimInstance_PlayerCharacterAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_AnimInstance_PlayerCharacterAnimInstance_PlayerCharacterAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerCharacterAnimInstance, UPlayerCharacterAnimInstance::StaticClass, TEXT("UPlayerCharacterAnimInstance"), &Z_Registration_Info_UClass_UPlayerCharacterAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerCharacterAnimInstance), 1047490764U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_AnimInstance_PlayerCharacterAnimInstance_PlayerCharacterAnimInstance_h_1930260363(TEXT("/Script/shooter_project"),
		Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_AnimInstance_PlayerCharacterAnimInstance_PlayerCharacterAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_shooter_project_Source_shooter_project_Private_AnimInstance_PlayerCharacterAnimInstance_PlayerCharacterAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
