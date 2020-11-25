// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TonksGameModeBase.generated.h"

class ABasePawn;
class ATankPlayerController;


UCLASS()
class TONKS_API ATonksGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	void ActorDied(AActor* DeadActor);
	void StartTurn();
	void EndTurn();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver();

private:
	void HandleGameStart();
	void HandeGameOver();

	int8 TotalTanks = 0;
	TArray<int32> TurnOrder;
	TArray<ABasePawn*> Tanks;
	ATankPlayerController* PlayerControllerRef;
	
};
