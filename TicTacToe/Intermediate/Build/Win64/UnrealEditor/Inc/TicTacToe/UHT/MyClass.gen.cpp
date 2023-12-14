// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TicTacToe/MyClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyClass() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	TICTACTOE_API UClass* Z_Construct_UClass_AMyClass();
	TICTACTOE_API UClass* Z_Construct_UClass_AMyClass_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TicTacToe();
// End Cross Module References
	void AMyClass::StaticRegisterNativesAMyClass()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyClass);
	UClass* Z_Construct_UClass_AMyClass_NoRegister()
	{
		return AMyClass::StaticClass();
	}
	struct Z_Construct_UClass_AMyClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TicTacToe,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyClass_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyClass_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyClass.h" },
		{ "ModuleRelativePath", "MyClass.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyClass_Statics::ClassParams = {
		&AMyClass::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyClass_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyClass_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMyClass()
	{
		if (!Z_Registration_Info_UClass_AMyClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyClass.OuterSingleton, Z_Construct_UClass_AMyClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyClass.OuterSingleton;
	}
	template<> TICTACTOE_API UClass* StaticClass<AMyClass>()
	{
		return AMyClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyClass);
	AMyClass::~AMyClass() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_MyClass_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_MyClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyClass, AMyClass::StaticClass, TEXT("AMyClass"), &Z_Registration_Info_UClass_AMyClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyClass), 77112618U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_MyClass_h_1854676599(TEXT("/Script/TicTacToe"),
		Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_MyClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_MyClass_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
