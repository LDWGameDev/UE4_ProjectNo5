// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_GameplayTagControl.generated.h"

class FGameplayTagContainer;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_GameplayTagControl : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTNO5_API IInterface_GameplayTagControl
{
	GENERATED_BODY()

public:
	virtual const FGameplayTagContainer& GetGameplayTagContainer() = 0;
};
