// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class colea4v8 : ModuleRules
{
	public colea4v8(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"ChaosVehicles",
			"PhysicsCore",
			"UMG",
			"Slate",
			"ArcGISMapsSDK"
		});

		PublicIncludePaths.AddRange(new string[] {
			"colea4v8",
			"colea4v8/SportsCar",
			"colea4v8/OffroadCar",
			"colea4v8/Variant_Offroad",
			"colea4v8/Variant_TimeTrial",
			"colea4v8/Variant_TimeTrial/UI"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "HTTP", "Json", "JsonUtilities" });

		PrivateDependencyModuleNames.AddRange(collection: new string[] { "ArcGISMapsSDK" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
