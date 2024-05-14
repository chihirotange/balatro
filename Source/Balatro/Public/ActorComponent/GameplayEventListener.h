// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "GameplayEventObserver.h"
#include "Components/ActorComponent.h"
#include "GameplayEventListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayActionExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiscardActionExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDealCardsActionExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCardPlayed, ACard*, Card, bool, IsLastCard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardDealt, ACard*, Card);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardDiscarded, ACard*, Card);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALATRO_API UGameplayEventListener : public UActorComponent, public IGameplayEventObserver
{
public:
	virtual void PlayDealCardEvent() override;

	virtual void DiscardCardEvent(ACard* DiscardedCard) override;

	virtual void PlayCardEvent(ACard* Card, bool IsLastCard) override;

	virtual void DealCardEvent(ACard* Card) override;

	virtual void PlayDiscardEvent() override;
	virtual void PlayActionEvent() override;

private:
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameplayEventListener();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//@TODO: maybe consider remove this
	UPROPERTY(BlueprintAssignable)
	FOnPlayActionExecuted OnPlayActionExecuted;

	//@TODO: maybe consider remove this
	UPROPERTY(BlueprintAssignable)
	FOnDiscardActionExecuted OnDiscardActionExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnDealCardsActionExecuted OnDealCardsActionExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnCardPlayed OnCardPlayed;

	UPROPERTY(BlueprintAssignable)
	FOnCardDealt OnCardDealt;

	UPROPERTY(BlueprintAssignable)
	FOnCardDiscarded OnCardDiscarded;
};
