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
	int32 userNum;

	void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);



	virtual FString GetName(const FUniqueNetId& UserId);

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	FString GetUserName();

	FString Name;


protected:
	class IOnlineSubsystem* OnlineSubsystem;

};
