// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/StateMachine/Player/PlayerBaseState.h"
#include "PlayerHumanBaseState.generated.h"


class ACharacter_PlayerHuman;
class UComponent_StateMachine;

/**
 * 
 */
UCLASS()
class PROJECTNO5_API UPlayerHumanBaseState : public UPlayerBaseState
{
	GENERATED_BODY()
	

/**
 * Properties
 */

public:
protected:
	ACharacter_PlayerHuman* m_CharacterPlayerHumanREF;
private:


/**
 * Functions
 */

public:
	UPlayerHumanBaseState();
	virtual void InitState(AActor* p_ActorREF, UComponent_StateMachine* p_StateMachineREF) override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void TickState(float p_DeltaTime) override;

	virtual void BindToCharacterDelegates();
	virtual void UnbindToCharacterDelegates();

protected:
private:

};
