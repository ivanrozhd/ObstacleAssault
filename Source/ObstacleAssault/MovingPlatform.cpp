// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(MyVector);
	StartLocation = GetActorLocation();
	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("Name of the object %s") , *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}


void AMovingPlatform::MovePlatform(float DeltaTime) {

	if (ShouldPlatformReturn()) {
		
		FVector Normal = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + Normal * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

	else {
            FVector CurrentLocation = GetActorLocation();
            CurrentLocation += PlatformVelocity * DeltaTime;
	        SetActorLocation(CurrentLocation);     
	}

}


void AMovingPlatform::RotatePlatform(float DeltaTime) {
	   AddActorLocalRotation(RotationVelocity * DeltaTime);
}


float AMovingPlatform::GetDistanceMoved()  const
{
	return  FVector::Dist(StartLocation, GetActorLocation());
}



bool AMovingPlatform::ShouldPlatformReturn() const 
{
 return  MoveDistance < GetDistanceMoved();
}
