// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlayerController_PlayerGameplay.h"
#include "Character/Player/Character_PlayerBase.h"


/**
 * 
 */

APlayerController_PlayerGameplay::APlayerController_PlayerGameplay()
{
	
}



/**
 * Override functions
 */

void APlayerController_PlayerGameplay::SetupInputComponent()
{
	Super::SetupInputComponent();
}



/**
 * Protected member functions
 */

void APlayerController_PlayerGameplay::BindInputAxis_MoveUp(float p_Value)
{
	Super::BindInputAxis_MoveUp(p_Value);

	ACharacter_PlayerBase* CharPlayerBase = Cast<ACharacter_PlayerBase>(GetPawn());
	if (CharPlayerBase != nullptr)
	{
		CharPlayerBase->HandleInputAxis_MoveUp(p_Value);
	}
}

void APlayerController_PlayerGameplay::BindInputAxis_MoveRight(float p_Value)
{
	Super::BindInputAxis_MoveRight(p_Value);

	ACharacter_PlayerBase* CharPlayerBase = Cast<ACharacter_PlayerBase>(GetPawn());
	if (CharPlayerBase != nullptr)
	{
		CharPlayerBase->HandleInputAxis_MoveRight(p_Value);
	}
}
