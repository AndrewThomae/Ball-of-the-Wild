// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallOfTheWild/BallOfTheWildGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallOfTheWildGameMode() {}
// Cross Module References
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_ABallOfTheWildGameMode_NoRegister();
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_ABallOfTheWildGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BallOfTheWild();
// End Cross Module References
	DEFINE_FUNCTION(ABallOfTheWildGameMode::execNewWorld)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NewWorld();
		P_NATIVE_END;
	}
	void ABallOfTheWildGameMode::StaticRegisterNativesABallOfTheWildGameMode()
	{
		UClass* Class = ABallOfTheWildGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "NewWorld", &ABallOfTheWildGameMode::execNewWorld },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "Multiplayer" },
		{ "ModuleRelativePath", "BallOfTheWildGameMode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABallOfTheWildGameMode, nullptr, "NewWorld", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABallOfTheWildGameMode);
	UClass* Z_Construct_UClass_ABallOfTheWildGameMode_NoRegister()
	{
		return ABallOfTheWildGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ABallOfTheWildGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABallOfTheWildGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BallOfTheWild,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABallOfTheWildGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABallOfTheWildGameMode_NewWorld, "NewWorld" }, // 616600766
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallOfTheWildGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BallOfTheWildGameMode.h" },
		{ "ModuleRelativePath", "BallOfTheWildGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABallOfTheWildGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallOfTheWildGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABallOfTheWildGameMode_Statics::ClassParams = {
		&ABallOfTheWildGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABallOfTheWildGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABallOfTheWildGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABallOfTheWildGameMode()
	{
		if (!Z_Registration_Info_UClass_ABallOfTheWildGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABallOfTheWildGameMode.OuterSingleton, Z_Construct_UClass_ABallOfTheWildGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABallOfTheWildGameMode.OuterSingleton;
	}
	template<> BALLOFTHEWILD_API UClass* StaticClass<ABallOfTheWildGameMode>()
	{
		return ABallOfTheWildGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABallOfTheWildGameMode);
	struct Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABallOfTheWildGameMode, ABallOfTheWildGameMode::StaticClass, TEXT("ABallOfTheWildGameMode"), &Z_Registration_Info_UClass_ABallOfTheWildGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABallOfTheWildGameMode), 512120261U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_206486094(TEXT("/Script/BallOfTheWild"),
		Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
