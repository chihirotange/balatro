// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CardDealer.h"

#include "Card.h"
#include "Card/DeckData.h"
#include "card/CardData.h"
#include "Core/BalatroGameState.h"

void ACardDealer::PrepareAvailableCards()
{
	if(!IsValid(DeckToDeal))
	{
		return;
	}
	auto Cards = DeckToDeal->Deck;
	for (auto Card : Cards)
	{
		CurrentCardsAvailable.Add(Card);
	}

	if(Shuffled && CurrentCardsAvailable.Num() > 0)
	{
		int32 LastIndex = CurrentCardsAvailable.Num() - 1;
		for (int32 i = 0; i <= LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				CurrentCardsAvailable.Swap(i, Index);
			}
		}
	}
}

// Sets default values
ACardDealer::ACardDealer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardDealer::BeginPlay()
{
	Super::BeginPlay();

	PrepareAvailableCards();
}

// Called every frame
void ACardDealer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ACard* ACardDealer::DealCard()
{
	if(IsValid(DeckToDeal) && IsValid(CardClass) && !CurrentCardsAvailable.IsEmpty())
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		auto DealtCard = GetWorld()->SpawnActor<ACard>(CardClass, SpawnInfo);

		if(DealtCard->Implements<UHasDataAsset>())
		{
			IHasDataAsset::Execute_SetDataAsset(DealtCard, CurrentCardsAvailable.Pop());
		}

		//notify card dealt
		auto GameState = GetWorld()->GetGameState<ABalatroGameState>();
		if(IsValid(GameState))
		{
			GameState->BroadcastDealCard(DealtCard);
		}
		return DealtCard;
	}
	return nullptr;
}

