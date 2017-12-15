// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::OnTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if(InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTank->FindComponentByClass<UTankAimingComponent>()->AimAt(PlayerTank->GetActorLocation());
		
		if (ControlledTank->FindComponentByClass<UTankAimingComponent>()->GetFiringState() == EFiringState::Locked)
		{
			ControlledTank->FindComponentByClass<UTankAimingComponent>()->Fire();
		}
		
	}
}
