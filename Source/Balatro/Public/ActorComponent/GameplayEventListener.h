// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEventObserver.h"
#include "Components/ActorComponent.h"
#include "GameplayEventListener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayActionExecuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiscardActionExecuted);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BALATRO_API UGameplayEventListener : public UActorComponent, public IGameplayEventObserver
{
public:
	virtual void PlayDiscardEvent() override;
	virtual void PlayActionEvent() override;

private:
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameplayEventListener();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnPlayActionExecuted OnPlayActionExecuted;

	UPROPERTY(BlueprintAssignable)
	FOnDiscardActionExecuted OnDiscardActionExecuted;
	
};
