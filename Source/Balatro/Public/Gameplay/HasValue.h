// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HasValue.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UHasValue : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALATRO_API IHasValue
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetValue();
	virtual int32 GetValue_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetValue(int32 Value);
	virtual void SetValue_Implementation(int32 Value);
};
