// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MessageParser.generated.h"

/**
 * 
 */
UCLASS()
class BALLOFTHEWILD_API UMessageParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static FString pushFront(FString oldMessage, char c);

	UFUNCTION(BlueprintCallable, Category = "String Parsing")
		static FString parseMessages(FString allMessages);

	UFUNCTION(BlueprintCallable, Category = "String Parsing")
		static FString appendString(FString oldString, FString newString);
};
