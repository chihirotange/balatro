// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasDataAsset.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UHasDataAsset : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALATRO_API IHasDataAsset
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UDataAsset* GetDataAsset();

	virtual UDataAsset* GetDataAsset_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetDataAsset(UDataAsset* DataAsset);

	virtual void SetDataAsset_Implementation(UDataAsset* DataAsset) = 0;
};
