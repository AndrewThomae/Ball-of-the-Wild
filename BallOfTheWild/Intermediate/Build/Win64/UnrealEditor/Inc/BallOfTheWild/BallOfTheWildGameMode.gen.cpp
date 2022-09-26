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
	void ABallOfTheWildGameMode::StaticRegisterNativesABallOfTheWildGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABallOfTheWildGameMode);
	UClass* Z_Construct_UClass_ABallOfTheWildGameMode_NoRegister()
	{
		return ABallOfTheWildGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ABallOfTheWildGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ Z_Construct_UClass_ABallOfTheWildGameMode, ABallOfTheWildGameMode::StaticClass, TEXT("ABallOfTheWildGameMode"), &Z_Registration_Info_UClass_ABallOfTheWildGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABallOfTheWildGameMode), 1771141233U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_4104711352(TEXT("/Script/BallOfTheWild"),
		Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_BallOfTheWildGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
