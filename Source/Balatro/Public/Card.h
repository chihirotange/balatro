// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HasDataAsset.h"
#include "GameFramework/Actor.h"
#include "Gameplay/HasValue.h"
#include "Gameplay/Disposable.h"
#include "Gameplay/HasSuit.h"
#include "Card.generated.h"

class UDataAssetContainer;

UCLASS(Abstract)
class BALATRO_API ACard : public AActor, public IHasValue, public IHasDataAsset, public IDisposable, public IHasSuit
{
public:
	virtual void SetSuit_Implementation(ECardSuit Suit) override;

	virtual ECardSuit GetSuit_Implementation() override;

	virtual void Dispose_Implementation() override;

	virtual UDataAsset* GetDataAsset_Implementation() override;
	virtual void SetDataAsset_Implementation(UDataAsset* DataAsset) override;

private:
	GENERATED_BODY()

public:
	virtual int32 GetValue_Implementation() override;

private:
	UPROPERTY(EditAnywhere)
	UDataAssetContainer* DataAssetContainer;
	
public:	
	// Sets default values for this actor's properties
	ACard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
