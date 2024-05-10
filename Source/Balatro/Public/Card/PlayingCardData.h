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
class BALATRO_API UPlayingCardData : public UCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int8 CardValue;

	UPROPERTY(EditAnywhere)
	ECardSuit Suit;
};
