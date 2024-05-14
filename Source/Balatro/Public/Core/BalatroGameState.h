// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "GameFramework/GameStateBase.h"
#include "Gameplay/GameplayState.h"
#include "BalatroGameState.generated.h"

class ACard;
class IGameplayEventObserver;
/**
 * 
 */
UCLASS()
class BALATRO_API ABalatroGameState : public AGameStateBase, public IGameplayState
{
public:
	virtual void SetTargetBind_Implementation(int64 Bind) override;
	virtual int64 GetTargetBind_Implementation() override;

private:
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<UObject*> GameplayEventListeners;

	int64 TargetBind;
	int64 CurrentScore;

public:
	void RegisterGameplayListener(UObject* Listener);

	UFUNCTION(BlueprintCallable)
	void UnsubscribeAllListeners();

	UFUNCTION(BlueprintCallable)
	void BroadcastPlayCommand();

	UFUNCTION(BlueprintCallable)
	void BroadcastDiscardCommand();

	UFUNCTION(BlueprintCallable)
	void BroadcastDealCardCommand();
	
	UFUNCTION(BlueprintCallable)
	void BroadcastPlayCardAction(ACard* Card, bool IsLastCard);

	UFUNCTION(BlueprintCallable)
	void BroadcastDealCard(ACard* Card);

	UFUNCTION(BlueprintCallable)
	void BroadcastDiscardCard(ACard* DiscardedCard);
};
