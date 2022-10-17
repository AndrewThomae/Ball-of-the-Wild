// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallOfTheWild/Public/BallOfTheWildGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallOfTheWildGameInstance() {}
// Cross Module References
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_UBallOfTheWildGameInstance_NoRegister();
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_UBallOfTheWildGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_BallOfTheWild();
// End Cross Module References
	DEFINE_FUNCTION(UBallOfTheWildGameInstance::execCreateSession)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateSession();
		P_NATIVE_END;
	}
	void UBallOfTheWildGameInstance::StaticRegisterNativesUBallOfTheWildGameInstance()
	{
		UClass* Class = UBallOfTheWildGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateSession", &UBallOfTheWildGameInstance::execCreateSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "Sessions" },
		{ "ModuleRelativePath", "Public/BallOfTheWildGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBallOfTheWildGameInstance, nullptr, "CreateSession", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBallOfTheWildGameInstance);
	UClass* Z_Construct_UClass_UBallOfTheWildGameInstance_NoRegister()
	{
		return UBallOfTheWildGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UBallOfTheWildGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_BallOfTheWild,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBallOfTheWildGameInstance_CreateSession, "CreateSession" }, // 4283437789
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BallOfTheWildGameInstance.h" },
		{ "ModuleRelativePath", "Public/BallOfTheWildGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBallOfTheWildGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::ClassParams = {
		&UBallOfTheWildGameInstance::StaticClass,
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
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBallOfTheWildGameInstance()
	{
		if (!Z_Registration_Info_UClass_UBallOfTheWildGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBallOfTheWildGameInstance.OuterSingleton, Z_Construct_UClass_UBallOfTheWildGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBallOfTheWildGameInstance.OuterSingleton;
	}
	template<> BALLOFTHEWILD_API UClass* StaticClass<UBallOfTheWildGameInstance>()
	{
		return UBallOfTheWildGameInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBallOfTheWildGameInstance);
	struct Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_Public_BallOfTheWildGameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_Public_BallOfTheWildGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBallOfTheWildGameInstance, UBallOfTheWildGameInstance::StaticClass, TEXT("UBallOfTheWildGameInstance"), &Z_Registration_Info_UClass_UBallOfTheWildGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBallOfTheWildGameInstance), 3076540662U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_Public_BallOfTheWildGameInstance_h_3788761536(TEXT("/Script/BallOfTheWild"),
		Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_Public_BallOfTheWildGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_Public_BallOfTheWildGameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
