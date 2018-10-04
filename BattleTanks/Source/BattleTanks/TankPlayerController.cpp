// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		AimTowardsCrosshair();
	}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		return;
	}

	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation))
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *OutHitLocation.ToString());
	
		// TODOTell controlled tank to aim at this point
	}
}

// Get World location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);


	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}