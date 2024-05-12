// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HasDataAsset.h"
#include "Components/ActorComponent.h"
#include "DataAssetContainer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALATRO_API UDataAssetContainer : public UActorComponent
{
public:
	virtual UDataAsset* GetDataAsset();
	virtual void SetDataAsset(UDataAsset* DataAsset);

private:
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UDataAsset* CurrentDataAsset;

public:	
	// Sets default values for this component's properties
	UDataAssetContainer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
