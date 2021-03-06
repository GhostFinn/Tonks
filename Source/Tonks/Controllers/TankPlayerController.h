// Tonks � 2020 Felipe Anargyrou. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATankPawn;

UCLASS()
class TONKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AddWidget();

protected:
	// Function to bind Input to functions
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* PawnToPossess) override;

private:
	void MoveInput(float Amount);
	void TurnInput(float Amount);
	void RotateInput(float Amount);
	void LookUpInput(float Amount);
	void AimInputPressed();
	void AimInputReleased();
	void FireInputPressed();
	void FireInputReleased();
	void EndTurnInput();


	ATankPawn* TankPawn;
};
