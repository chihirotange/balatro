// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card/CardData.h"
#include "PlayingCardData.generated.h"

enum class ECardSuit : uint8;
/**
 * 
 */
UCLASS()
class BALATRO_API UPlayingCardData : public UCardData, public IHasValue
{
public:
	virtual int32 GetValue_Implementation() override;

private:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 CardValue;

	UPROPERTY(EditAnywhere)
	ECardSuit Suit;
};
