// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

int32 ACard::GetValue_Implementation()
{
	if(IsValid(CardData) && CardData->Implements<UHasValue>())
	{
		return IHasValue::Execute_GetValue(CardData);
	}
	return 0;
}

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

