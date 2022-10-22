// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BallOfTheWildGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BALLOFTHEWILD_API UBallOfTheWildGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBallOfTheWildGameInstance();

	virtual void Init();

	void Login();

	void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void CreateSession();

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void DestroySession();


	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	void OnDestroySessionComplete(FName SessionName,bool bWasSuccessful);

protected:
	class IOnlineSubsystem* OnlineSubsystem;

};
