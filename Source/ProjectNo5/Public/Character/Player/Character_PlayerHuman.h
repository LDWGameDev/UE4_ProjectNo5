// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/Character_PlayerBase.h"
#include "Character_PlayerHuman.generated.h"


/**
 * 
 */

UCLASS()
class PROJECTNO5_API ACharacter_PlayerHuman : public ACharacter_PlayerBase
{
	GENERATED_BODY()
	

/**
 * Properties
 */
public:
protected:
private:



/**
 * Functions
 */
public:
	ACharacter_PlayerHuman();
	virtual void Tick(float DeltaTime) override;

	virtual void HandleInputAxis_MoveUp(float p_Value) override;
	virtual void HandleInputAxis_MoveRight(float p_Value) override;

protected:
	virtual void BeginPlay() override;

private:

};
