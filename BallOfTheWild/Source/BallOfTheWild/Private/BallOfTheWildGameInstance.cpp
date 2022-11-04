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
}

void UBallOfTheWildGameInstance::Login(FString name) {
	if (OnlineSubsystem) {
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface()) {
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("127.0.0.1:8081");
			Credentials.Token = name;

			Credentials.Type = FString("developer");
			Identity->OnLoginCompleteDelegates->AddUObject(this, &UBallOfTheWildGameInstance::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
}

void UBallOfTheWildGameInstance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error) {
	UE_LOG(LogTemp, Warning, TEXT("Logged In: %d"), bWasSuccessful);
	if (bWasSuccessful) {
		userNum = LocalUserNum;
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

void UBallOfTheWildGameInstance::AddFriendJoinHandler()
{
	IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface();
	EOS
}

void UBallOfTheWildGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Session Destroyed: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnDestroySessionCompleteDelegates(this);
			UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, 0);
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