// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_PlayerBase.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTNO5_API APlayerController_PlayerBase : public APlayerController
{
	GENERATED_BODY()
	

/**
 * Functions
 */
public:
	APlayerController_PlayerBase();
protected:
	virtual void SetupInputComponent() override;

	virtual void BindInputAxis_MoveUp(float p_Value);
	virtual void BindInputAxis_MoveRight(float p_Value);
private:
};
