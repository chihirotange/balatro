// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BalatroGameState.h"
#include "ActorComponent/GameplayEventObserver.h"

void ABalatroGameState::SetTargetBind_Implementation(int64 Bind)
{
	TargetBind = Bind;
}

int64 ABalatroGameState::GetTargetBind_Implementation()
{
	return TargetBind;
}

void ABalatroGameState::RegisterGameplayListener(UObject* Listener)
{
	if(Listener)
	{
		GameplayEventListeners.Add(Listener);
	}
}

void ABalatroGameState::UnsubscribeAllListeners()
{
	GameplayEventListeners.Empty();
}

void ABalatroGameState::BroadcastPlayCommand()
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->PlayActionEvent();
		}
	}
}

void ABalatroGameState::BroadcastDiscardCommand()
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->PlayDiscardEvent();
		}
	}
}

void ABalatroGameState::BroadcastDealCardCommand()
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->PlayDealCardEvent();
		}
	}
}

void ABalatroGameState::BroadcastPlayCardAction(ACard* Card, bool IsLastCard)
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->PlayCardEvent(Card, IsLastCard);
		}
	}
}

void ABalatroGameState::BroadcastDealCard(ACard* Card)
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->DealCardEvent(Card);
		}
	}
}

void ABalatroGameState::BroadcastDiscardCard(ACard* DiscardedCard)
{
	for (auto Listener : GameplayEventListeners)
	{
		auto Observer = Cast<IGameplayEventObserver>(Listener);
		if(Observer)
		{
			Observer->DiscardCardEvent(DiscardedCard);
		}
	}
}
