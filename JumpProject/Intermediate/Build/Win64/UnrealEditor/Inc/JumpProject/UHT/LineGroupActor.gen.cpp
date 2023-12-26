// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JumpProject/Private/Actor/LineGroupActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLineGroupActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	JUMPPROJECT_API UClass* Z_Construct_UClass_ALineGroupActor();
	JUMPPROJECT_API UClass* Z_Construct_UClass_ALineGroupActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_JumpProject();
// End Cross Module References
	void ALineGroupActor::StaticRegisterNativesALineGroupActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALineGroupActor);
	UClass* Z_Construct_UClass_ALineGroupActor_NoRegister()
	{
		return ALineGroupActor::StaticClass();
	}
	struct Z_Construct_UClass_ALineGroupActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LineGroupRootComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LineGroupRootComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALineGroupActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_JumpProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALineGroupActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALineGroupActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actor/LineGroupActor.h" },
		{ "ModuleRelativePath", "Private/Actor/LineGroupActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALineGroupActor_Statics::NewProp_LineGroupRootComponent_MetaData[] = {
		{ "Category", "LineGroupActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc7\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd4\xb4\xcf\xb4\xef\xbf\xbd.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/Actor/LineGroupActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc7\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd4\xb4\xcf\xb4\xef\xbf\xbd." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALineGroupActor_Statics::NewProp_LineGroupRootComponent = { "LineGroupRootComponent", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALineGroupActor, LineGroupRootComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALineGroupActor_Statics::NewProp_LineGroupRootComponent_MetaData), Z_Construct_UClass_ALineGroupActor_Statics::NewProp_LineGroupRootComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALineGroupActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALineGroupActor_Statics::NewProp_LineGroupRootComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALineGroupActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALineGroupActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALineGroupActor_Statics::ClassParams = {
		&ALineGroupActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ALineGroupActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ALineGroupActor_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALineGroupActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ALineGroupActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALineGroupActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ALineGroupActor()
	{
		if (!Z_Registration_Info_UClass_ALineGroupActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALineGroupActor.OuterSingleton, Z_Construct_UClass_ALineGroupActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALineGroupActor.OuterSingleton;
	}
	template<> JUMPPROJECT_API UClass* StaticClass<ALineGroupActor>()
	{
		return ALineGroupActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALineGroupActor);
	ALineGroupActor::~ALineGroupActor() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Actor_LineGroupActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Actor_LineGroupActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ALineGroupActor, ALineGroupActor::StaticClass, TEXT("ALineGroupActor"), &Z_Registration_Info_UClass_ALineGroupActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALineGroupActor), 2458300119U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Actor_LineGroupActor_h_2394919545(TEXT("/Script/JumpProject"),
		Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Actor_LineGroupActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_JumpProject_Source_JumpProject_Private_Actor_LineGroupActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
