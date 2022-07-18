// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateMachine/Player/PlayerHumanBaseState.h"
#include "Characters/Character/Player/Character_PlayerHuman.h"

#include "Kismet/KismetSystemLibrary.h"



/**
 * 
 */

UPlayerHumanBaseState::UPlayerHumanBaseState()
{

}



/**
 * Override functions
 */

void UPlayerHumanBaseState::InitState(AActor* p_ActorREF, UComponent_StateMachine* p_StateMachineREF)
{
	Super::InitState(p_ActorREF, p_StateMachineREF);
	m_CharacterPlayerHumanREF = Cast<ACharacter_PlayerHuman>(p_ActorREF);
	BindToCharacterDelegates();
}

void UPlayerHumanBaseState::EnterState()
{
	Super::EnterState();
	if (m_CharacterPlayerHumanREF == nullptr) return;

	//FString DisplayName = UKismetSystemLibrary::GetDisplayName(this);
	//UE_LOG(LogTemp, Warning, TEXT("PlayerHumanBaseState - Enter() - %s"), *DisplayName);
}

void UPlayerHumanBaseState::ExitState()
{
	Super::ExitState();
	if (m_CharacterPlayerHumanREF == nullptr) return;
}

void UPlayerHumanBaseState::TickState(float p_DeltaTime)
{
	Super::TickState(p_DeltaTime);
	if (m_CharacterPlayerHumanREF == nullptr) return;
}

void UPlayerHumanBaseState::BindToCharacterDelegates()
{
	if (m_CharacterPlayerHumanREF == nullptr) return;
}

void UPlayerHumanBaseState::UnbindToCharacterDelegates()
{
	if (m_CharacterPlayerHumanREF == nullptr) return;
}