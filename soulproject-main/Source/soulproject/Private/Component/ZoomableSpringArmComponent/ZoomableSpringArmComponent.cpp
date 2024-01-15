// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ZoomableSpringArmComponent/ZoomableSpringArmComponent.h"

UZoomableSpringArmComponent::UZoomableSpringArmComponent()
{
	ZoomMultiplier = 20.f;

	ZoomLengthMax = 400.f;
	ZoomLengthMin = 100.f;
}

void UZoomableSpringArmComponent::ZoomCamera(float axis)
{
	TargetArmLength -= axis * ZoomMultiplier;
	TargetArmLength = FMath::Clamp(TargetArmLength, ZoomLengthMin, ZoomLengthMax);
}
