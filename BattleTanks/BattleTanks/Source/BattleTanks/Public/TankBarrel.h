// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 20.0;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevation = 30.0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinimumElevation = 0.0;

};
