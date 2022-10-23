// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Engine/GameInstance.h"
#include "Engine/NetworkDelegates.h"
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

	void Login(int c);

	void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void CreateSession();

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void DestroySession();
	TSharedPtr<class FOnlineSessionSearch> SearchSettings;

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void FindSessions();

	void OnFindSessionComplete(bool bWasSuccessful);

	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	virtual FString GetName(const FUniqueNetId& UserId);

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	FString GetUserName();

	FString Name;

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	void OnDestroySessionComplete(FName SessionName,bool bWasSuccessful);

protected:
	class IOnlineSubsystem* OnlineSubsystem;

};
