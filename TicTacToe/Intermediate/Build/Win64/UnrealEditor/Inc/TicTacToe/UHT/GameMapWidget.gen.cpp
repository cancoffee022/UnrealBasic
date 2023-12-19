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
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked22)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked22();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked21)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked21();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked20)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked20();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked12)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked12();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked11)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked11();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked10)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked10();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked02)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked02();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked01)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked01();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked00)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked00();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMapWidget::execOnGameBoardClicked)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_GET_PROPERTY(FIntProperty,Z_Param_y);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGameBoardClicked(Z_Param_x,Z_Param_y);
		P_NATIVE_END;
	}
	void UGameMapWidget::StaticRegisterNativesUGameMapWidget()
	{
		UClass* Class = UGameMapWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnGameBoardClicked", &UGameMapWidget::execOnGameBoardClicked },
			{ "OnGameBoardClicked00", &UGameMapWidget::execOnGameBoardClicked00 },
			{ "OnGameBoardClicked01", &UGameMapWidget::execOnGameBoardClicked01 },
			{ "OnGameBoardClicked02", &UGameMapWidget::execOnGameBoardClicked02 },
			{ "OnGameBoardClicked10", &UGameMapWidget::execOnGameBoardClicked10 },
			{ "OnGameBoardClicked11", &UGameMapWidget::execOnGameBoardClicked11 },
			{ "OnGameBoardClicked12", &UGameMapWidget::execOnGameBoardClicked12 },
			{ "OnGameBoardClicked20", &UGameMapWidget::execOnGameBoardClicked20 },
			{ "OnGameBoardClicked21", &UGameMapWidget::execOnGameBoardClicked21 },
			{ "OnGameBoardClicked22", &UGameMapWidget::execOnGameBoardClicked22 },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics
	{
		struct GameMapWidget_eventOnGameBoardClicked_Parms
		{
			int32 x;
			int32 y;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_x;
		static const UECodeGen_Private::FIntPropertyParams NewProp_y;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameMapWidget_eventOnGameBoardClicked_Parms, x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::NewProp_y = { "y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameMapWidget_eventOnGameBoardClicked_Parms, y), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::NewProp_y,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked", nullptr, nullptr, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::GameMapWidget_eventOnGameBoardClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::GameMapWidget_eventOnGameBoardClicked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked00", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked01", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked02", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked10", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked11", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked12", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked20", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked21", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Widget/GameMapWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMapWidget, nullptr, "OnGameBoardClicked22", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameMapWidget);
	UClass* Z_Construct_UClass_UGameMapWidget_NoRegister()
	{
		return UGameMapWidget::StaticClass();
	}
	struct Z_Construct_UClass_UGameMapWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameMapWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked, "OnGameBoardClicked" }, // 278970508
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked00, "OnGameBoardClicked00" }, // 3205461899
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked01, "OnGameBoardClicked01" }, // 1663715502
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked02, "OnGameBoardClicked02" }, // 1621750827
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked10, "OnGameBoardClicked10" }, // 1900898085
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked11, "OnGameBoardClicked11" }, // 3152222110
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked12, "OnGameBoardClicked12" }, // 2377257970
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked20, "OnGameBoardClicked20" }, // 2526633452
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked21, "OnGameBoardClicked21" }, // 594738909
		{ &Z_Construct_UFunction_UGameMapWidget_OnGameBoardClicked22, "OnGameBoardClicked22" }, // 515457626
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameMapWidget_Statics::FuncInfo) < 2048);
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	struct Z_CompiledInDeferFile_FID_Users_User_Desktop_UnrealProject_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Desktop_UnrealProject_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameMapWidget, UGameMapWidget::StaticClass, TEXT("UGameMapWidget"), &Z_Registration_Info_UClass_UGameMapWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameMapWidget), 434008676U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Desktop_UnrealProject_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_3873372109(TEXT("/Script/TicTacToe"),
		Z_CompiledInDeferFile_FID_Users_User_Desktop_UnrealProject_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Desktop_UnrealProject_UnrealBasic_TicTacToe_Source_TicTacToe_Private_Widget_GameMapWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
