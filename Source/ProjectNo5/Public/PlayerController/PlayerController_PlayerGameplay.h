// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/PlayerController_PlayerBase.h"
#include "PlayerController_PlayerGameplay.generated.h"



class ACharacter_PlayerBase;

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
	virtual void BeginPlay();
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	// Input handling functions. Binds to player intput in SetupInputComponent()
	virtual void BindInputAxis_MoveUp(float p_Value) override;
	virtual void BindInputAxis_MoveRight(float p_Value) override;
	virtual void BindInputAxis_MiddleMouseScroll(float p_Value) override;

private:



/**
 * Properties
 */

public:

protected:
	UPROPERTY()
		ACharacter_PlayerBase* m_ControlledCharacterPlayerBaseREF;
private:

};
