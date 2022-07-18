// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlayerController_PlayerGameplay.h"

#include "Characters/Character/Player/Character_PlayerBase.h"
#include "System/Settings/SettingsManager.h"


/**
 * 
 */

APlayerController_PlayerGameplay::APlayerController_PlayerGameplay()
{
	
}




/**
 * Override functions
 */

void APlayerController_PlayerGameplay::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
}

void APlayerController_PlayerGameplay::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void APlayerController_PlayerGameplay::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	m_ControlledCharacterPlayerBaseREF = Cast<ACharacter_PlayerBase>(InPawn);
}

void APlayerController_PlayerGameplay::OnUnPossess()
{
	Super::OnUnPossess();
	m_ControlledCharacterPlayerBaseREF = nullptr;
}





/**
 * Protected member functions
 */

void APlayerController_PlayerGameplay::BindInputAxis_MoveUp(float p_Value)
{
	if (p_Value == 0.0f) return;
	if (m_ControlledCharacterPlayerBaseREF != nullptr)
	{
		m_ControlledCharacterPlayerBaseREF->HandleInputAxis_MoveUp(p_Value);
	}
}

void APlayerController_PlayerGameplay::BindInputAxis_MoveRight(float p_Value)
{
	if (p_Value == 0.0f) return;
	if (m_ControlledCharacterPlayerBaseREF != nullptr)
	{
		m_ControlledCharacterPlayerBaseREF->HandleInputAxis_MoveRight(p_Value);
	}
}

void APlayerController_PlayerGameplay::BindInputAxis_MiddleMouseScroll(float p_Value)
{
	if (p_Value == 0.0f) return;
	// Checks conditions for being in gameplay or not. If not, like in option menu for example, not execute the code below
	if (m_SettingManagerREF != nullptr)
	{
		m_SettingManagerREF->UpdateSettingValue_CameraDistance(p_Value);
	}
}
