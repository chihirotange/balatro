// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BALATRO_API Enums
{
public:
	Enums();
	~Enums();
};

UENUM()
enum class ECardSuit : uint8
{
	None,
	Spade,
	Club,
	Diamond,
	Heart,
};
