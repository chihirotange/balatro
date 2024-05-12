// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Disposable.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UDisposable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALATRO_API IDisposable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Dispose();
	virtual void Dispose_Implementation() = 0;
};
