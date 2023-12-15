// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TicTacToe/Private/Widget/GameMapWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameMapWidget() {}
// Cross Module References
	TICTACTOE_API UClass* Z_Construct_UClass_UGameMapWidget();
	TICTACTOE_API UClass* Z_Construct_UClass_UGameMapWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_TicTacToe();
// End Cross Module References
	void UGameMapWidget::StaticRegisterNativesUGameMapWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameMapWidget);
	UClass* Z_Construct_UClass_UGameMapWidget_NoRegister()
	{
		return UGameMapWidget::StaticClass();
	}
	struct Z_Construct_UClass_UGameMapWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameMapWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_TicTacToe,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMapWidget_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameMapWidget_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Widget/GameMapWidget.h" },
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameMapWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameMapWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameMapWidget_Statics::ClassParams = {
		&UGameMapWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00A010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMapWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameMapWidget_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UGameMapWidget()
	{
		if (!Z_Registration_Info_UClass_UGameMapWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameMapWidget.OuterSingleton, Z_Construct_UClass_UGameMapWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameMapWidget.OuterSingleton;
	}
	template<> TICTACTOE_API UClass* StaticClass<UGameMapWidget>()
	{
		return UGameMapWidget::StaticClass();
	}
	UGameMapWidget::UGameMapWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameMapWidget);
	UGameMapWidget::~UGameMapWidget() {}
	struct Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameMapWidget, UGameMapWidget::StaticClass, TEXT("UGameMapWidget"), &Z_Registration_Info_UClass_UGameMapWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameMapWidget), 4109165486U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_145031221(TEXT("/Script/TicTacToe"),
		Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
