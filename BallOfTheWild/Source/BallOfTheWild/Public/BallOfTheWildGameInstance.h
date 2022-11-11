// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <eos_sdk.h>
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
	FString LocalId;


	EOS_HPlatform Platform;
	EOS_HPlatform PlatformHandle;
	EOS_HStats StatsHandle;
	EOS_HAuth AuthHandle;

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void Login(FString name);
	int32 userNum;

	void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	UFUNCTION(BlueprintCallable, Category = "Sessions")
		void DestroySession();

	//UFUNCTION(BlueprintCallable, Category = "Sessions")
	//void AddFriendJoinHandler();


	//UFUNCTION(BlueprintCallable, Category = "Sessions")
		//void CreateSession();

	virtual FString GetName(const FUniqueNetId& UserId);

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
		FString GetUserName();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void PleaseWork();

	FString Name;


	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

protected:
	class IOnlineSubsystem* OnlineSubsystem;
	static void EOS_CALL StatsIngestCallbackFn(const EOS_Stats_IngestStatCompleteCallbackInfo* Data);
	static void EOS_CALL LoginCompleteCallbackFn(const EOS_Auth_LoginCallbackInfo* Data);
};