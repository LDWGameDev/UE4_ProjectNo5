// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateMachine/Component_StateMachine.h"
#include "Characters/StateMachine/BaseState.h"

#include "Kismet/KismetSystemLibrary.h"


/**
 * 
 */

UComponent_StateMachine::UComponent_StateMachine()
{
	PrimaryComponentTick.bCanEverTick = true;
	m_HistoryStateLength = 10;
}




/**
 * Override function
 */

void UComponent_StateMachine::BeginPlay()
{
	Super::BeginPlay();
	m_HistoryStateList.Reserve(m_HistoryStateLength);
}

void UComponent_StateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (b_IsActive && m_CurrentState != nullptr)
	{
		m_CurrentState->TickState(DeltaTime);
	}
}




/**
 * Public member functions
 */

TArray<UBaseState*>* UComponent_StateMachine::GetStateList()
{
	return &m_StateList;
}

TArray<UBaseState*>* UComponent_StateMachine::GetHistoryStateList()
{
	return &m_HistoryStateList;
}

void UComponent_StateMachine::ActivateStateMachine(bool p_DoActivate, const FString& p_StartStateID)
{
	b_IsActive = p_DoActivate;
	if (p_DoActivate)
	{
		for (UBaseState* TempState : m_StateList)
		{
			if (TempState->GetStateID().Equals(p_StartStateID, ESearchCase::IgnoreCase))
			{
				m_CurrentState = TempState;
				m_CurrentState->EnterState();
				return;
			}
		}
		ChangeToDefaultState();
	}
	else
	{
		if (m_CurrentState != nullptr)
		{
			m_CurrentState->ExitState();
			m_CurrentState = nullptr;
		}
	}
}

void UComponent_StateMachine::ChangeState(const FString& p_NewStateID)
{
	for (UBaseState* TempState : m_StateList)
	{
		if (TempState->GetStateID().Equals(p_NewStateID, ESearchCase::IgnoreCase) && !TempState->CheckIsInCooldownTime())
		{
			if (m_CurrentState != nullptr)
			{
				m_CurrentState->ExitState();
				AddStateToHistory(m_CurrentState);
			}
			TempState->EnterState();
			m_CurrentState = TempState;
			return;
		}
	}
	ChangeToDefaultState();
}




/**
 * Private member functions
 */

void UComponent_StateMachine::AddStateToHistory(UBaseState* p_HistoryState)
{
	if (p_HistoryState == nullptr) return;
	if (m_HistoryStateList.Num() < m_HistoryStateLength)
	{
		m_HistoryStateList.Add(p_HistoryState);
	}
	else
	{
		m_HistoryStateList.RemoveAt(0, 1, false);
		m_HistoryStateList.Add(p_HistoryState);
	}

	//////////////////////////////////// Debug
	//UE_LOG(LogTemp, Warning, TEXT("StateHistoryLength: %d"), m_HistoryStateList.Num());
	//for (auto& HistoryState : m_HistoryStateList)
	//{
	//	FString StateID = HistoryState->GetStateID();
	//	UE_LOG(LogTemp, Warning, TEXT("StateHistory: %s"), *StateID);
	//}
}

void UComponent_StateMachine::ChangeToDefaultState()
{
	for (UBaseState* TempState : m_StateList)
	{
		if (TempState->GetStateID().Equals(m_DefaultStateIDWhenFail, ESearchCase::IgnoreCase))
		{
			if (m_CurrentState != nullptr)
			{
				m_CurrentState->ExitState();
				AddStateToHistory(m_CurrentState);
			}
			TempState->EnterState();
			m_CurrentState = TempState;
			return;
		}
	}
}
