// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
		// Find the distance to the Tank
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		// Check to see if the Tnak is in range
		if (Distance <= FireRange)
		{
			// If in range, rotate towards the Tank
			RotateTurret(Tank->GetActorLocation());
		}

	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
