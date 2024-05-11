// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DeckData.generated.h"

class UCardData;
/**
 * 
 */
UCLASS()
class BALATRO_API UDeckData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<UCardData*> Deck;
};
