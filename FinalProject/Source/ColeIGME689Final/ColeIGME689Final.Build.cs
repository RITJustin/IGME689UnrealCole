// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ColeIGME689Final : ModuleRules
{
	public ColeIGME689Final(ReadOnlyTargetRules Target) : base(Target)
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
			"ColeIGME689Final",
			"ColeIGME689Final/Variant_Horror",
			"ColeIGME689Final/Variant_Horror/UI",
			"ColeIGME689Final/Variant_Shooter",
			"ColeIGME689Final/Variant_Shooter/AI",
			"ColeIGME689Final/Variant_Shooter/UI",
			"ColeIGME689Final/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
