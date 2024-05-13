// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasSuit.generated.h"

enum class ECardSuit : uint8;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHasSuit : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALATRO_API IHasSuit
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	ECardSuit GetSuit();
	virtual ECardSuit GetSuit_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetSuit(ECardSuit Suit);
	virtual void SetSuit_Implementation(ECardSuit Suit) = 0;
};
