// Copyright Epic Games, Inc. All Rights Reserved.

#include "BallOfTheWildGameMode.h"
#include "BallOfTheWildCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABallOfTheWildGameMode::ABallOfTheWildGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABallOfTheWildGameMode::PostLogin(APlayerController* NewPlayer) {
	if (playerCount > 1) {
		FActorSpawnParameters SpawnInfo;
		GetWorld()->SpawnActor<APawn>(UGameplayStatics::GetActorOfClass(GetWorld(), DefaultPawnClass)->GetClass(), SpawnInfo);
	}
	playerCount++;
}