// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BallOfTheWild : ModuleRules
{
	public BallOfTheWild(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "OnlineSubsystem", "OnlineSubsystemEOS" });
	}
}
