// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateMachine/Player/PlayerHumanState_SwordLocomotion.h"
#include "Characters/Character/Player/Character_PlayerHuman.h"



/**
 * 
 */

UPlayerHumanState_SwordLocomotion::UPlayerHumanState_SwordLocomotion()
{
	m_StateID = TEXT("PlayerHumanState_SwordLocomotion");
}



/**
 * Override functions
 */

void UPlayerHumanState_SwordLocomotion::EnterState()
{
	Super::EnterState();
}

void UPlayerHumanState_SwordLocomotion::ExitState()
{
	Super::ExitState();
}

void UPlayerHumanState_SwordLocomotion::TickState(float p_DeltaTime)
{
	Super::TickState(p_DeltaTime);
}

void UPlayerHumanState_SwordLocomotion::BindToCharacterDelegates()
{
	Super::BindToCharacterDelegates();
	m_CharacterPlayerHumanREF->m_DelegateCharacterPlayerBase_MoveUp.AddDynamic(this, &UPlayerHumanState_SwordLocomotion::HandleDelegate_CharacterPlayerBase_MoveUp);
	m_CharacterPlayerHumanREF->m_DelegateCharacterPlayerBase_MoveRight.AddDynamic(this, &UPlayerHumanState_SwordLocomotion::HandleDelegate_CharacterPlayerBase_MoveRight);
}

void UPlayerHumanState_SwordLocomotion::HandleDelegate_CharacterPlayerBase_MoveUp(float p_Value)
{
	if (!b_IsInState) return;
	m_CharacterPlayerHumanREF->MoveCharacterUp(p_Value);
}

void UPlayerHumanState_SwordLocomotion::HandleDelegate_CharacterPlayerBase_MoveRight(float p_Value)
{
	if (!b_IsInState) return;
	m_CharacterPlayerHumanREF->MoveCharacterRight(p_Value);
}
