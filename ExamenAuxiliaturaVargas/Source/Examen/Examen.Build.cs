// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Examen : ModuleRules
{
	public Examen(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
