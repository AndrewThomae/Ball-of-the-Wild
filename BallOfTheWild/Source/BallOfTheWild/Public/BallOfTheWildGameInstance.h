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

	UFUNCTION(BlueprintCallable, Category = "Sessions")
	void CreateSession();

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

protected:
	class IOnlineSubsystem* OnlineSubsystem;

};
