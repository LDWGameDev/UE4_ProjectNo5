// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/PlayerController_PlayerBase.h"
#include "PlayerController_PlayerGameplay.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNO5_API APlayerController_PlayerGameplay : public APlayerController_PlayerBase
{
	GENERATED_BODY()
	

/**
 * Functions
 */
public:
	APlayerController_PlayerGameplay();

protected:
	virtual void SetupInputComponent() override;

	virtual void BindInputAxis_MoveUp(float p_Value) override;
	virtual void BindInputAxis_MoveRight(float p_Value) override;
private:
};
