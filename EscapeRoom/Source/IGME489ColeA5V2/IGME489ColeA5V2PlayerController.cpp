// Copyright Epic Games, Inc. All Rights Reserved.


#include "IGME489ColeA5V2PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "IGME489ColeA5V2CameraManager.h"
#include "Blueprint/UserWidget.h"
#include "IGME489ColeA5V2.h"
#include "Widgets/Input/SVirtualJoystick.h"

AIGME489ColeA5V2PlayerController::AIGME489ColeA5V2PlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AIGME489ColeA5V2CameraManager::StaticClass();
}

void AIGME489ColeA5V2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogIGME489ColeA5V2, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AIGME489ColeA5V2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
