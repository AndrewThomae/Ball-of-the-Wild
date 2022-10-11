// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BALLOFTHEWILD_MessageParser_generated_h
#error "MessageParser.generated.h already included, missing '#pragma once' in MessageParser.h"
#endif
#define BALLOFTHEWILD_MessageParser_generated_h

#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_SPARSE_DATA
#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execappendString); \
	DECLARE_FUNCTION(execparseMessages);


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execappendString); \
	DECLARE_FUNCTION(execparseMessages);


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMessageParser(); \
	friend struct Z_Construct_UClass_UMessageParser_Statics; \
public: \
	DECLARE_CLASS(UMessageParser, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/BallOfTheWild"), NO_API) \
	DECLARE_SERIALIZER(UMessageParser)


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUMessageParser(); \
	friend struct Z_Construct_UClass_UMessageParser_Statics; \
public: \
	DECLARE_CLASS(UMessageParser, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/BallOfTheWild"), NO_API) \
	DECLARE_SERIALIZER(UMessageParser)


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMessageParser(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMessageParser) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMessageParser); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMessageParser); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMessageParser(UMessageParser&&); \
	NO_API UMessageParser(const UMessageParser&); \
public:


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMessageParser(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMessageParser(UMessageParser&&); \
	NO_API UMessageParser(const UMessageParser&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMessageParser); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMessageParser); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMessageParser)


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_12_PROLOG
#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_SPARSE_DATA \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_RPC_WRAPPERS \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_INCLASS \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_SPARSE_DATA \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_INCLASS_NO_PURE_DECLS \
	FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BALLOFTHEWILD_API UClass* StaticClass<class UMessageParser>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BallOfTheWild_Source_BallOfTheWild_MessageParser_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
