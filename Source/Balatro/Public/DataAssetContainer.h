// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HasDataAsset.h"
#include "Components/ActorComponent.h"
#include "DataAssetContainer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALATRO_API UDataAssetContainer : public UActorComponent, public IHasDataAsset
{
public:
	virtual UDataAsset* GetDataAsset_Implementation() override;

private:
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UDataAsset* DataAsset;

public:	
	// Sets default values for this component's properties
	UDataAssetContainer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
