// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTanks.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 10000;

private:
	void BeginPlay() override;

	UFUNCTION()
	void OnTankDeath();

	virtual void SetPawn(APawn* InPawn) override;
	
	void Tick(float DeltaTime) override;
};
