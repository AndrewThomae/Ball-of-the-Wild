// Copyright Epic Games, Inc. All Rights Reserved.

#include "BallOfTheWildGameMode.h"
#include "BallOfTheWildCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABallOfTheWildGameMode::ABallOfTheWildGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
		//DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	DefaultPawnClass = nullptr;
}
