// Fill out your copyright notice in the Description page of Project Settings.


#include "BallOfTheWildGameInstance.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UBallOfTheWildGameInstance::UBallOfTheWildGameInstance() {

}

void UBallOfTheWildGameInstance::Init() {
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();
	
}

void UBallOfTheWildGameInstance::CreateSession() {
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			FOnlineSessionSettings SessionSettings;
			SessionSettings.bIsDedicated = false;
			SessionSettings.bShouldAdvertise = true;
			SessionSettings.bIsLANMatch = true;
			SessionSettings.NumPublicConnections = 5;
			SessionSettings.bAllowJoinInProgress = true;
			SessionSettings.bAllowJoinViaPresence = true;

			SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UBallOfTheWildGameInstance::OnCreateSessionComplete);
			SessionPtr->CreateSession(0, FName("Test Session"), SessionSettings);
		}
	}
}

void UBallOfTheWildGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Success: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnCreateSessionCompleteDelegates(this);
		}
	}
}