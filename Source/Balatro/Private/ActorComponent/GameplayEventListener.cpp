// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/GameplayEventListener.h"

#include "Core/BalatroGameState.h"
#include "GameFramework/GameState.h"

// Sets default values for this component's properties
UGameplayEventListener::UGameplayEventListener()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameplayEventListener::BeginPlay()
{
	Super::BeginPlay();
	
	auto GameState = GetWorld() != nullptr ? GetWorld()->GetGameState<ABalatroGameState>() : nullptr;

	if (IsValid(GameState))
	{
		GameState->RegisterGameplayListener(this);
	}
}


// Called every frame
void UGameplayEventListener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGameplayEventListener::DiscardCardEvent(ACard* DiscardedCard)
{
	OnCardDiscarded.Broadcast(DiscardedCard);
}

void UGameplayEventListener::PlayCardEvent(ACard* Card)
{
	OnCardPlayed.Broadcast(Card);
}

void UGameplayEventListener::DealCardEvent(ACard* Card)
{
	OnCardDealt.Broadcast(Card);
}

void UGameplayEventListener::PlayCardsEvent(const TArray<ACard*> Cards)
{
	OnCardsPlayed.Broadcast(Cards);
}

void UGameplayEventListener::PlayDiscardEvent()
{
	OnDiscardActionExecuted.Broadcast();
}

void UGameplayEventListener::PlayActionEvent()
{
	OnPlayActionExecuted.Broadcast();
}



