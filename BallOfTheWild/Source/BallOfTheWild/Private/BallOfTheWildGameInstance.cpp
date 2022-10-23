// Fill out your copyright notice in the Description page of Project Settings.



#include "BallOfTheWildGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/OnlineSessionInterface.h"

UBallOfTheWildGameInstance::UBallOfTheWildGameInstance() {

}

void UBallOfTheWildGameInstance::Init() {
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();
	Login(0);
}

void UBallOfTheWildGameInstance::Login(int c) {
	if (OnlineSubsystem) {
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("127.0.0.1:8081");
			if (c != 0) {
				Credentials.Token = FString("Default1");
			}
			else {
				Credentials.Token = FString("Default1");
			}
			
			Credentials.Type = FString("developer");
			Identity->OnLoginCompleteDelegates->AddUObject(this, &UBallOfTheWildGameInstance::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
}

void UBallOfTheWildGameInstance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error) {
	UE_LOG(LogTemp, Warning, TEXT("Logged In: %d"), bWasSuccessful);
	if (bWasSuccessful) {
		if (OnlineSubsystem) {
			if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
				Identity->ClearOnLoginCompleteDelegates(0, this);
				Name = GetName(UserId);
			}
		}
	}
	else {
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
			Identity->ClearOnLoginCompleteDelegates(0, this);
		}
		Login(1);
	}
}

void UBallOfTheWildGameInstance::CreateSession() {
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			FOnlineSessionSettings SessionSettings;
			SessionSettings.bIsDedicated = false;
			SessionSettings.bShouldAdvertise = true;
			SessionSettings.bIsLANMatch = false;
			SessionSettings.NumPublicConnections = 5;
			SessionSettings.bAllowJoinInProgress = true;
			SessionSettings.bAllowJoinViaPresence = true;
			SessionSettings.bUsesPresence = true;
			SessionSettings.bUseLobbiesIfAvailable = true;

			SessionSettings.Set(SEARCH_KEYWORDS, FString("EXLobby"), EOnlineDataAdvertisementType::ViaOnlineService);

			SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UBallOfTheWildGameInstance::OnCreateSessionComplete);
			SessionPtr->CreateSession(0, FName("Test Session"), SessionSettings);
		}
	}
}

void UBallOfTheWildGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Session Created: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnCreateSessionCompleteDelegates(this);
			UGameplayStatics::OpenLevel(GetWorld(), FName("/Game/MultiplayerMap1"));
		}
	}
}

void UBallOfTheWildGameInstance::DestroySession() {
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->OnDestroySessionCompleteDelegates.AddUObject(this, &UBallOfTheWildGameInstance::OnDestroySessionComplete);
			SessionPtr->DestroySession(FName("Test Session"));
		}
	}
}

void UBallOfTheWildGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Session Destroyed: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnDestroySessionCompleteDelegates(this);
			UKismetSystemLibrary::QuitGame(this,nullptr,EQuitPreference::Quit,0);
		}
	}
}

void UBallOfTheWildGameInstance::FindSessions() {
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SearchSettings = MakeShareable(new FOnlineSessionSearch());
			SearchSettings->QuerySettings.Set(SEARCH_KEYWORDS, FString("EXLobby"), EOnlineComparisonOp::Equals);
			SearchSettings->QuerySettings.Set(SEARCH_LOBBIES, true, EOnlineComparisonOp::Equals);
			
			SessionPtr->OnFindSessionsCompleteDelegates.AddUObject(this, &UBallOfTheWildGameInstance::OnFindSessionComplete);
			SessionPtr->FindSessions(0, SearchSettings.ToSharedRef());
		}
	}
}

void UBallOfTheWildGameInstance::OnFindSessionComplete(bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Lobby Search Success: %d"), bWasSuccessful);
	if (bWasSuccessful) {
		UE_LOG(LogTemp, Warning, TEXT("Lobbies Found: %d"), SearchSettings->SearchResults.Num()); if (OnlineSubsystem) {
			if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
				if (SearchSettings->SearchResults.Num()) {
					SessionPtr->OnJoinSessionCompleteDelegates.AddUObject(this, &UBallOfTheWildGameInstance::OnJoinSessionComplete);
					SessionPtr->JoinSession(0, FName("Test Session"), SearchSettings->SearchResults[0]);
				}
			}
		}
	}
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnFindSessionsCompleteDelegates(this);
		}
	}
}

void UBallOfTheWildGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result) {
	if (OnlineSubsystem && Result == EOnJoinSessionCompleteResult::Success) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			FString ConnectionInfo = FString();
			SessionPtr->GetResolvedConnectString(FName("Test Session"), ConnectionInfo);
			if (!ConnectionInfo.IsEmpty()) {
				if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
					PC->ClientTravel(ConnectionInfo, ETravelType::TRAVEL_Absolute);
					FURL NewURL(nullptr, *ConnectionInfo, ETravelType::TRAVEL_Absolute);
					FString BrowseError;
					if (GEngine->Browse(GEngine->GetWorldContextFromWorldChecked(this->GetWorld()), NewURL, BrowseError) == EBrowseReturnVal::Failure) {
						UE_LOG(LogTemp, Error, TEXT("Failed to start browse: %s"), *BrowseError);
					}
				}
			}
		}
	}
}

FString UBallOfTheWildGameInstance::GetName(const FUniqueNetId& UserId)
{
	IOnlineIdentityPtr IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	return IdentityPtr->GetPlayerNickname(UserId);
}

FString UBallOfTheWildGameInstance::GetUserName() {
	return Name;
}
