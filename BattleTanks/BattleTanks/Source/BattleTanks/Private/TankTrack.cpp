// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "BattleTanks.h"

void UTankTrack::SetThrottle(float throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%f throttle %s"), throttle, *Name);
}



