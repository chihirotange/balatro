// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BalatroGameState.generated.h"

class ACard;
class IGameplayEventObserver;
/**
 * 
 */
UCLASS()
class BALATRO_API ABalatroGameState : public AGameStateBase
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TArray<UObject*> GameplayEventListeners;

public:
	void RegisterGameplayListener(UObject* Listener);

	UFUNCTION(BlueprintCallable)
	void UnsubscribeAllListeners();

	UFUNCTION(BlueprintCallable)
	void BroadcastPlayAction();

	UFUNCTION(BlueprintCallable)
	void BroadcastDiscardAction();

	UFUNCTION(BlueprintCallable)
	void BroadcastPlayCardsAction(const TArray<ACard*> Cards);
	
};
