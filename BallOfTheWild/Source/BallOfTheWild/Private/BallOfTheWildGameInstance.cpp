// Fill out your copyright notice in the Description page of Project Settings.


#include "BallOfTheWildGameInstance.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineIdentityInterface.h"

UBallOfTheWildGameInstance::UBallOfTheWildGameInstance() {

}

void UBallOfTheWildGameInstance::Init() {
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();
	Login();
}

void UBallOfTheWildGameInstance::Login() {
	if (OnlineSubsystem) {
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("127.0.0.1:8081");
			Credentials.Token = FString("Default");
			Credentials.Type = FString("developer");
			Identity->OnLoginCompleteDelegates->AddUObject(this, &UBallOfTheWildGameInstance::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
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

void UBallOfTheWildGameInstance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error) {
	UE_LOG(LogTemp, Warning, TEXT("Logged In: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
			Identity->ClearOnLoginCompleteDelegates(0, this);
		}
	}
}

void UBallOfTheWildGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Session Created: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnCreateSessionCompleteDelegates(this);
		}
	}
}