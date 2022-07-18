// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateMachine/BaseState.h"
#include "Misc/DateTime.h"
#include "Characters/StateMachine/Component_StateMachine.h"



/**
 * 
 */ 

UBaseState::UBaseState()
{
	m_EnterStateTime = FDateTime::UtcNow();
	m_ExitStateTime = FDateTime::UtcNow();
	b_IsInState = false;
}




/**
 * Public member functions
 */

void UBaseState::InitState(AActor* p_ActorREF, UComponent_StateMachine* p_StateMachineREF)
{
	m_StateMachineCompREF = p_StateMachineREF;
}

void UBaseState::EnterState()
{
	if (m_StateMachineCompREF == nullptr) return;
	m_EnterStateTime = FDateTime::UtcNow();
	b_IsInState = true;
}

void UBaseState::ExitState()
{
	if (m_StateMachineCompREF == nullptr) return;
	m_ExitStateTime = FDateTime::UtcNow();
	b_IsInState = false;
}

void UBaseState::TickState(float p_DeltaTime)
{
	if (m_StateMachineCompREF == nullptr) return;
}

const FString& UBaseState::GetStateID()
{
	return m_StateID;
}

const FGameplayTagContainer& UBaseState::GetStateTagContainer()
{
	return m_StateTagContainer;
}

float UBaseState::GetStateTime_LastEnterToNow()
{
	FTimespan TempTimespan = FDateTime::UtcNow() - m_EnterStateTime;
	return TempTimespan.GetSeconds();
}

float UBaseState::GetStateTime_LastExitToNow()
{
	FTimespan TempTimespan = FDateTime::UtcNow() - m_ExitStateTime;
	return TempTimespan.GetSeconds();
}

float UBaseState::GetStateTime_LastDuration()
{
	if (b_IsInState) return 0.0f;
	FTimespan TempTimespan = m_ExitStateTime - m_EnterStateTime;
	return TempTimespan.GetSeconds();
}

bool UBaseState::CheckIsInCooldownTime()
{
	if (b_IsInState) return false;
	return GetStateTime_LastExitToNow() < m_CooldownTime;
}

bool UBaseState::CheckForHoldingTime(float p_HoldingTime)
{
	if (b_IsInState) return true;
	return p_HoldingTime > GetStateTime_LastExitToNow();
}

void UBaseState::SetExitStateTimeToNow()
{
	if (b_IsInState) return;
	m_ExitStateTime = FDateTime::UtcNow();
}

void UBaseState::ChangeState(const FString& p_NewStateID)
{
	if (m_StateMachineCompREF != nullptr) m_StateMachineCompREF->ChangeState(p_NewStateID);
}
