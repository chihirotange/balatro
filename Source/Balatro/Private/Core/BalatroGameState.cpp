// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BalatroGameState.h"
#include "ActorComponent/GameplayEventObserver.h"

void ABalatroGameState::RegisterGameplayListener(UObject* Listener)
{
	if(Listener)
	{
		GameplayEventListeners.Add(Listener);
	}
}

void ABalatroGameState::BroadcastPlayAction()
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

void ABalatroGameState::BroadcastDiscardAction()
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
