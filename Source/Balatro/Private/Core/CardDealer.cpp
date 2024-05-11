// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CardDealer.h"

#include "Card/DeckData.h"

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
	
}

// Called every frame
void ACardDealer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACardDealer::DealCards()
{
	if(DeckToDeal)
	{
		auto Deck = DeckToDeal->Deck;
		if(!DeckToDeal)
		{
			return;
		}
		for (auto Card : Deck)
		{
			// GetWorld()->SpawnActor<()
		}
	}
}

