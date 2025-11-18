// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IGME489ColeA5V2 : ModuleRules
{
	public IGME489ColeA5V2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"IGME489ColeA5V2",
			"IGME489ColeA5V2/Variant_Horror",
			"IGME489ColeA5V2/Variant_Horror/UI",
			"IGME489ColeA5V2/Variant_Shooter",
			"IGME489ColeA5V2/Variant_Shooter/AI",
			"IGME489ColeA5V2/Variant_Shooter/UI",
			"IGME489ColeA5V2/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
