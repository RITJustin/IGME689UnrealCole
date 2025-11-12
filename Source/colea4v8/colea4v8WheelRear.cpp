// Copyright Epic Games, Inc. All Rights Reserved.

#include "colea4v8WheelRear.h"
#include "UObject/ConstructorHelpers.h"

Ucolea4v8WheelRear::Ucolea4v8WheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}