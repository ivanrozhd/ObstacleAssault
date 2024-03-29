

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
    UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(1,2,3);
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 1000;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
    bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};