// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TONKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(FVector MoveDirection);
	void Turn(FQuat TurnDirection);
	void Rotate(FQuat RotationDirection);
	void LookUp(FQuat LookUpDirection);
	void Fire();
	void AimMode();
	void MoveMode();

private:
	// COMPONENTS

	// Mesh Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BodyMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* GunMesh;

	

	// Camera Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

	// Dummy Components

	// Points to where the Projectile will spawn when player Fires
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;

	// Points to where the camera will go when the player goes into Aim Mode (When holding Right Mouse Click)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* AimModePoint;

	// VARIABLES

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;
	// Spring Arm Length used in MoveMode; Obtained from whatever value is set in the Blueprint
	float OriginalSpringArmLength = 0.f;
	// Boolean to determine if Player is in Move or Rotate/Aim mode (ie. hold mouse right click)
	bool bIsInAimMode = false;
	// To ensure a smooth transition between Aim Mode and Move Mode cameras, we're using this variable to store
	// the Controller's original Rotation before moving into Aim Mode;
	// In Aim Mode, the Player Controller rotation gets replaced by the GunMesh's WorldRotation
	FRotator MoveModeRotation;
};
