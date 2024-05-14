// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayEventObserver.generated.h"

class ACard;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameplayEventObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALATRO_API IGameplayEventObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void PlayActionEvent() = 0;

	virtual void PlayDiscardEvent() = 0;

	virtual void PlayDealCardEvent() = 0;

	virtual void PlayCardEvent(ACard* Card, bool IsLastCard) = 0;

	virtual void DealCardEvent(ACard* Card) = 0;

	virtual void DiscardCardEvent(ACard* DiscardedCard) = 0;
};
