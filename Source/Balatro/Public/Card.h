// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/HasValue.h"
#include "Card/CardData.h"
#include "Card.generated.h"

UCLASS(Abstract)
class BALATRO_API ACard : public AActor, public IHasValue
{
public:
	virtual int32 GetValue_Implementation() override;

private:
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UCardData* CardData;
	
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
