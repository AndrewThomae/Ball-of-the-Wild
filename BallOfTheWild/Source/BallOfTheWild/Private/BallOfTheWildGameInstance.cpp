// Fill out your copyright notice in the Description page of Project Settings.



#include "BallOfTheWildGameInstance.h"
#include "eos_platform_prereqs.h"
#include <eos_sdk.h>
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "eos_friends.h"
#include <eos_sessions.h>
#include <eos_presence.h>
#include <eos_ui.h>
#include <cassert>

UBallOfTheWildGameInstance::UBallOfTheWildGameInstance() {

}

void UBallOfTheWildGameInstance::Init() {
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();

	FPlatformProcess::GetDllHandle(TEXT("$(ModuleDir)\\EOSSDK-Win65-Shipping.dll"));

	EOS_InitializeOptions EOSOptions = {};
	EOSOptions.ApiVersion = EOS_INITIALIZE_API_LATEST;
	EOSOptions.ProductName = "Ball of The Wild";
	EOSOptions.ProductVersion = "alpha 1.0";

	EOS_Initialize(&EOSOptions);

	EOS_Platform_Options pOptions = {};
	pOptions.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
	pOptions.ProductId = "027b433d10e14b0b91cf824d59c78108";
	pOptions.SandboxId = "7da70d326f174fdb81e230d6ac3ef737";
	EOS_Platform_ClientCredentials creds = {};
	creds.ClientId = "xyza7891AnJyHxefFOvuUuKO93EAgWNU";
	creds.ClientSecret = "jQ2v/5GI5kHkEjEwOiQn7cHCl8Y0EjqkoJBLoOF6Osw";
	pOptions.ClientCredentials = creds;
	pOptions.bIsServer = EOS_FALSE;
	pOptions.EncryptionKey = "645267556B58703273357638782F413F4428472B4B6250655368566D59713374";
	pOptions.DeploymentId = "f7cc0c54eda34b74bf00b6d1b1045af5";
	Platform = EOS_Platform_Create(&pOptions);
	if (Platform) {
		UE_LOG(LogTemp, Warning, TEXT("Platform Create Success"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Platform Create Failed"));
	}
}

void EOS_CALL UBallOfTheWildGameInstance::StatsIngestCallbackFn(const const EOS_Stats_IngestStatCompleteCallbackInfo* Data) {
	assert(Data != NULL);
	if (Data->ResultCode != EOS_EResult::EOS_Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ingest Stat Error"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Ingest Stat Success"));
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


void UBallOfTheWildGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful) {
	UE_LOG(LogTemp, Warning, TEXT("Session Destroyed: %d"), bWasSuccessful);
	if (OnlineSubsystem) {
		if (IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface()) {
			SessionPtr->ClearOnDestroySessionCompleteDelegates(this);
			UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, 0);
		}
	}
}


/*void UBallOfTheWildGameInstance::CreateSession()
{
	EOS_Sessions_CreateSessionModificationOptions CreateOptions = {};
	CreateOptions.ApiVersion = EOS_SESSIONS_CREATESESSIONMODIFICATION_API_LATEST;

	// The top - level, game - specific filtering information for session searches. This criteria should be set with mostly static, coarse settings, often formatted like "GameMode:Region:MapName".
	CreateOptions.BucketId = "SessionSample:Region";
	CreateOptions.MaxPlayers = 5;
	CreateOptions.SessionName = "Test Session";
	CreateOptions.LocalUserId = 0;
	CreateOptions.bPresenceEnabled = true;
	CreateOptions.bSanctionsEnabled = EOS_FALSE;

	EOS_Platform_GetSessionsInterface(FPlatform)

	EOS_HSessionModification ModificationHandle = NULL;
	EOS_EResult CreateResult = EOS_Sessions_CreateSessionModification(NULL, &CreateOptions, &ModificationHandle);


	EOS_SessionModification_SetPermissionLevelOptions PermOptions = {};
	PermOptions.ApiVersion = EOS_SESSIONMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	PermOptions.PermissionLevel = EOS_EOnlineSessionPermissionLevel::EOS_OSPF_PublicAdvertised;
	EOS_EResult SetPermsResult = EOS_SessionModification_SetPermissionLevel(ModificationHandle, &PermOptions);
	if (SetPermsResult != EOS_EResult::EOS_Success)
	{
		//FDebugLog::LogError(L"Session Matchmaking: failed to set permissions. Error code: %ls", FStringUtils::Widen(EOS_EResult_ToString(SetPermsResult)).c_str());
		EOS_SessionModification_Release(ModificationHandle);
		//return false;
	}

	EOS_SessionModification_SetJoinInProgressAllowedOptions JIPOptions = {};
	JIPOptions.ApiVersion = EOS_SESSIONMODIFICATION_SETJOININPROGRESSALLOWED_API_LATEST;
	JIPOptions.bAllowJoinInProgress = EOS_TRUE;
	EOS_EResult SetJIPResult = EOS_SessionModification_SetJoinInProgressAllowed(ModificationHandle, &JIPOptions);
	if (SetJIPResult != EOS_EResult::EOS_Success)
	{
		//FDebugLog::LogError(L"Session Matchmaking: failed to set 'join in progress allowed' flag. Error code: %ls", FStringUtils::Widen(EOS_EResult_ToString(SetJIPResult)).c_str());
		EOS_SessionModification_Release(ModificationHandle);
		//return false;
	}

	EOS_SessionModification_SetInvitesAllowedOptions IAOptions = {};
	IAOptions.ApiVersion = EOS_SESSIONMODIFICATION_SETINVITESALLOWED_API_LATEST;
	IAOptions.bInvitesAllowed = EOS_TRUE;
	EOS_EResult SetIAResult = EOS_SessionModification_SetInvitesAllowed(ModificationHandle, &IAOptions);
	if (SetIAResult != EOS_EResult::EOS_Success)
	{
		//FDebugLog::LogError(L"Session Matchmaking: failed to set invites allowed. Error code: %ls", FStringUtils::Widen(EOS_EResult_ToString(SetIAResult)).c_str());
		EOS_SessionModification_Release(ModificationHandle);
		//return false;
	}


	EOS_Sessions_AttributeData AttrData;
	AttrData.ApiVersion = EOS_SESSIONS_SESSIONATTRIBUTEDATA_API_LATEST;

	EOS_SessionModification_AddAttributeOptions AttrOptions = {};
	AttrOptions.ApiVersion = EOS_SESSIONMODIFICATION_ADDATTRIBUTE_API_LATEST;
	AttrOptions.SessionAttribute = &AttrData;

	//Set bucket id
	AttrData.Key = EOS_SESSIONS_SEARCH_BUCKET_ID;
	AttrData.Value.AsUtf8 = "SessionSample:Region";
	AttrData.ValueType = EOS_EAttributeType::EOS_AT_STRING;
	EOS_EResult SetAttrResult = EOS_SessionModification_AddAttribute(ModificationHandle, &AttrOptions);
	if (SetAttrResult != EOS_EResult::EOS_Success)
	{
		//FDebugLog::LogError(L"Session Matchmaking: failed to set a bucket id attribute. Error code: %ls", FStringUtils::Widen(EOS_EResult_ToString(SetAttrResult)).c_str());
		EOS_SessionModification_Release(ModificationHandle);
		//return false;
	}

	//Set other attributes
	for (const FSession::Attribute& NextAttribute : Session.Attributes)
	{
		AttrData.Key = NextAttribute.Key.c_str();

		switch (NextAttribute.ValueType)
		{
		case FSession::Attribute::Bool:
			AttrData.ValueType = EOS_ESessionAttributeType::EOS_SAT_Boolean;
			AttrData.Value.AsBool = NextAttribute.AsBool;
			break;
		case FSession::Attribute::Double:
			AttrData.ValueType = EOS_ESessionAttributeType::EOS_SAT_Double;
			AttrData.Value.AsDouble = NextAttribute.AsDouble;
			break;
		case FSession::Attribute::Int64:
			AttrData.ValueType = EOS_ESessionAttributeType::EOS_SAT_Int64;
			AttrData.Value.AsInt64 = NextAttribute.AsInt64;
			break;
		case FSession::Attribute::String:
			AttrData.ValueType = EOS_ESessionAttributeType::EOS_AT_STRING;
			AttrData.Value.AsUtf8 = NextAttribute.AsString.c_str();
			break;
		}

		AttrOptions.AdvertisementType = NextAttribute.Advertisement;
		EOS_EResult SetAttrResult = EOS_SessionModification_AddAttribute(ModificationHandle, &AttrOptions);
		if (SetAttrResult != EOS_EResult::EOS_Success)
		{
			FDebugLog::LogError(L"Session Matchmaking: failed to set an attribute: %ls. Error code: %ls", NextAttribute.Key.c_str(), FStringUtils::Widen(EOS_EResult_ToString(SetAttrResult)).c_str());
			EOS_SessionModification_Release(ModificationHandle);
			return false;
		}
	}


	EOS_Sessions_UpdateSessionOptions UpdateOptions = {};
	UpdateOptions.ApiVersion = EOS_SESSIONS_UPDATESESSION_API_LATEST;
	UpdateOptions.SessionModificationHandle = ModificationHandle;
	EOS_Sessions_UpdateSession(SessionsHandle, &UpdateOptions, nullptr, OnUpdateSessionCompleteCallback_ForCreate);

	EOS_SessionModification_Release(ModificationHandle);

	return true;
}*/

FString UBallOfTheWildGameInstance::GetName(const FUniqueNetId& UserId)
{
	IOnlineIdentityPtr IdentityPtr = OnlineSubsystem->GetIdentityInterface();
	return IdentityPtr->GetPlayerNickname(UserId);
}

FString UBallOfTheWildGameInstance::GetUserName() {
	return Name;
}