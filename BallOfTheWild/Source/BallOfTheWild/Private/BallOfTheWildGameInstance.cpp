// Fill out your copyright notice in the Description page of Project Settings.



#include "BallOfTheWildGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineStatsInterface.h"
#include "OnlineSubsystemUtils.h"
#include "eos_init.h"

#include <eos_sdk.h>
#include <eos_stats.h>

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
				FString LocalId = *UserId.ToString();
				int32 index = LocalId.Find("|");
				FString LocalId2 = LocalId.RightChop(index);
				UE_LOG(LogTemp, Warning, TEXT("Logged In: %s, userNum: %d, LocalId: %s, Index: %d, New LocalId: %s"), *Name, LocalUserNum, *UserId.ToString(), index, *LocalId2);
				

				IOnlineSubsystem* Subsystem = Online::GetSubsystem(this->GetWorld());
				IOnlineStatsPtr StatsInterface = Subsystem->GetStatsInterface();

				FOnlineStatsUserUpdatedStats Stat = FOnlineStatsUserUpdatedStats(Identity->GetUniquePlayerId(0).ToSharedRef());

				// For each of the stats to upload, provide the StatName (matching what
				// is defined in the Epic Online Services portal) and the int32 value.
				// The EOnlineStatModificationType is ignored, as the stat type is defined
				// in the portal.
				//
				// You can add multiple entries to the Stats property to send more than one
				// stat value in a single request.
				Stat.Stats.Add("Experience", FOnlineStatUpdate(100, FOnlineStatUpdate::EOnlineStatModificationType::Unknown));

				TArray<FOnlineStatsUserUpdatedStats> Stats;
				Stats.Add(Stat);
				FString PlayerId = (*Identity->GetUniquePlayerId(0)).ToString();
				UE_LOG(LogTemp, Warning, TEXT("UniquePlayerId: %s"), *PlayerId);
				StatsInterface->UpdateStats(
					Identity->GetUniquePlayerId(0).ToSharedRef(),
					Stats,
					FOnlineStatsUpdateStatsComplete::CreateLambda([](
						const FOnlineError& ResultState)
						{
							// Check `ResultState.bSucceeded`.
						}));








				/*EOS_InitializeOptions SDKOptions = {};
				SDKOptions.ApiVersion = EOS_INITIALIZE_API_LATEST;
				SDKOptions.AllocateMemoryFunction = nullptr;
				SDKOptions.ReallocateMemoryFunction = nullptr;
				SDKOptions.ReleaseMemoryFunction = nullptr;
				SDKOptions.ProductName = "Ball of the Wild";
				SDKOptions.ProductVersion = "1.0";
				SDKOptions.Reserved = nullptr;
				SDKOptions.SystemInitializeOptions = nullptr;
				SDKOptions.OverrideThreadAffinity = nullptr;

				EOS_EResult InitResult = EOS_Initialize(&SDKOptions);

				EOS_Stats_IngestStatOptions StatsIngestOptions = {};
				StatsIngestOptions.ApiVersion = EOS_STATS_INGESTSTAT_API_LATEST;
				StatsIngestOptions.LocalUserId = (EOS_ProductUserId) LocalId2.ToBlob;
				StatsIngestOptions.TargetUserId = (EOS_ProductUserId)LocalId2.ToBlob;
				StatsIngestOptions.StatsCount = 1;

				EOS_Stats_IngestData* IngestData = new EOS_Stats_IngestData[StatsIngestOptions.StatsCount];

				IngestData[0].ApiVersion = EOS_STATS_INGESTDATA_API_LATEST;
				IngestData[0].StatName = "Experience";
				IngestData[0].IngestAmount = 100;

				StatsIngestOptions.Stats = IngestData;

				EOS_Platform_Options PlatformOptions = {};
				PlatformOptions.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
				PlatformOptions.bIsServer = false;
				PlatformOptions.EncryptionKey = "1111111111111111111111111111111111111111111111111111111111111111";
				PlatformOptions.OverrideCountryCode = nullptr;
				PlatformOptions.OverrideLocaleCode = nullptr;
				PlatformOptions.Flags = EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D9 | EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D10 | EOS_PF_WINDOWS_ENABLE_OVERLAY_OPENGL; // Enable overlay support for D3D9/10 and OpenGL. This sample uses D3D11 or SDL.
				static char Buffer[1024] = { 0 };
				PlatformOptions.CacheDirectory = Buffer;

				EOS_HPlatform PlatformHandle = EOS_Platform_Create(&PlatformOptions);
				EOS_HStats StatsHandle = EOS_Platform_GetStatsInterface(PlatformHandle);

				EOS_Stats_IngestStat(StatsHandle, &StatsIngestOptions, nullptr, NULL);*/
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