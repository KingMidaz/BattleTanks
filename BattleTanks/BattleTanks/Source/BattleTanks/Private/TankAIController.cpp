// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AITank = GetAIControlledTank();
	ATank* PlayerPawn = GetPlayerTank();

	if (PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found %s"), *PlayerPawn->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player controlled tank found"));
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}