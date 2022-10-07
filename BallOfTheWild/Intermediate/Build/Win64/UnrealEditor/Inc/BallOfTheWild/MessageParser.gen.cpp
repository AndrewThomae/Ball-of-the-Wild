// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallOfTheWild/MessageParser.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMessageParser() {}
// Cross Module References
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_UMessageParser_NoRegister();
	BALLOFTHEWILD_API UClass* Z_Construct_UClass_UMessageParser();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_BallOfTheWild();
// End Cross Module References
	DEFINE_FUNCTION(UMessageParser::execappendString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_oldString);
		P_GET_PROPERTY(FStrProperty,Z_Param_newString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UMessageParser::appendString(Z_Param_oldString,Z_Param_newString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMessageParser::execparseMessages)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_allMessages);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UMessageParser::parseMessages(Z_Param_allMessages);
		P_NATIVE_END;
	}
	void UMessageParser::StaticRegisterNativesUMessageParser()
	{
		UClass* Class = UMessageParser::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "appendString", &UMessageParser::execappendString },
			{ "parseMessages", &UMessageParser::execparseMessages },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMessageParser_appendString_Statics
	{
		struct MessageParser_eventappendString_Parms
		{
			FString oldString;
			FString newString;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_oldString;
		static const UECodeGen_Private::FStrPropertyParams NewProp_newString;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_oldString = { "oldString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MessageParser_eventappendString_Parms, oldString), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_newString = { "newString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MessageParser_eventappendString_Parms, newString), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MessageParser_eventappendString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMessageParser_appendString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_oldString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_newString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMessageParser_appendString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMessageParser_appendString_Statics::Function_MetaDataParams[] = {
		{ "Category", "String Parsing" },
		{ "ModuleRelativePath", "MessageParser.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMessageParser_appendString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMessageParser, nullptr, "appendString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMessageParser_appendString_Statics::MessageParser_eventappendString_Parms), Z_Construct_UFunction_UMessageParser_appendString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMessageParser_appendString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMessageParser_appendString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMessageParser_appendString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMessageParser_appendString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMessageParser_appendString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMessageParser_parseMessages_Statics
	{
		struct MessageParser_eventparseMessages_Parms
		{
			FString allMessages;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_allMessages;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMessageParser_parseMessages_Statics::NewProp_allMessages = { "allMessages", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MessageParser_eventparseMessages_Parms, allMessages), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMessageParser_parseMessages_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MessageParser_eventparseMessages_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMessageParser_parseMessages_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMessageParser_parseMessages_Statics::NewProp_allMessages,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMessageParser_parseMessages_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMessageParser_parseMessages_Statics::Function_MetaDataParams[] = {
		{ "Category", "String Parsing" },
		{ "ModuleRelativePath", "MessageParser.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMessageParser_parseMessages_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMessageParser, nullptr, "parseMessages", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMessageParser_parseMessages_Statics::MessageParser_eventparseMessages_Parms), Z_Construct_UFunction_UMessageParser_parseMessages_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMessageParser_parseMessages_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMessageParser_parseMessages_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMessageParser_parseMessages_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMessageParser_parseMessages()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMessageParser_parseMessages_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMessageParser);
	UClass* Z_Construct_UClass_UMessageParser_NoRegister()
	{
		return UMessageParser::StaticClass();
	}
	struct Z_Construct_UClass_UMessageParser_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMessageParser_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_BallOfTheWild,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMessageParser_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMessageParser_appendString, "appendString" }, // 1240861807
		{ &Z_Construct_UFunction_UMessageParser_parseMessages, "parseMessages" }, // 1050094060
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMessageParser_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MessageParser.h" },
		{ "ModuleRelativePath", "MessageParser.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMessageParser_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMessageParser>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMessageParser_Statics::ClassParams = {
		&UMessageParser::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMessageParser_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMessageParser_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMessageParser()
	{
		if (!Z_Registration_Info_UClass_UMessageParser.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMessageParser.OuterSingleton, Z_Construct_UClass_UMessageParser_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMessageParser.OuterSingleton;
	}
	template<> BALLOFTHEWILD_API UClass* StaticClass<UMessageParser>()
	{
		return UMessageParser::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMessageParser);
	struct Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMessageParser, UMessageParser::StaticClass, TEXT("UMessageParser"), &Z_Registration_Info_UClass_UMessageParser, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMessageParser), 2100699424U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_1279591261(TEXT("/Script/BallOfTheWild"),
		Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
