// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

#include "DataAssetContainer.h"
#include "Core/Enums.h"

void ACard::SetSuit_Implementation(ECardSuit Suit)
{
}

ECardSuit ACard::GetSuit_Implementation()
{
	auto DataAsset = DataAssetContainer->GetDataAsset();
	if(IsValid(DataAsset) && DataAsset->Implements<UHasSuit>())
	{
		return IHasSuit::Execute_GetSuit(DataAsset);
	}
	return ECardSuit::None;
}

void ACard::Dispose_Implementation()
{
}

UDataAsset* ACard::GetDataAsset_Implementation()
{
	return DataAssetContainer->GetDataAsset();
}

void ACard::SetDataAsset_Implementation(UDataAsset* DataAsset)
{
	DataAssetContainer->SetDataAsset(DataAsset);
}

int32 ACard::GetValue_Implementation()
{
	auto DA = DataAssetContainer->GetDataAsset();
	if(DA && DA->Implements<UHasValue>())
	{
		return IHasValue::Execute_GetValue(DA);
	}
	return 0;
}

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DataAssetContainer = CreateDefaultSubobject<UDataAssetContainer>(TEXT("Data Asset Container"));
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

