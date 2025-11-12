// Copyright Epic Games, Inc. All Rights Reserved.

#include "colea4v8WheelFront.h"
#include "UObject/ConstructorHelpers.h"

Ucolea4v8WheelFront::Ucolea4v8WheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}