// Fill out your copyright notice in the Description page of Project Settings.


#include "Card/PlayingCardData.h"

void UPlayingCardData::SetSuit_Implementation(ECardSuit Suit)
{
}

ECardSuit UPlayingCardData::GetSuit_Implementation()
{
	return CardSuit;
}

int32 UPlayingCardData::GetValue_Implementation()
{
	return CardValue;
}
