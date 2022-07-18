// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/StateMachine/Player/PlayerHumanState_Sword_BaseState.h"
#include "PlayerHumanState_SwordLocomotion.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNO5_API UPlayerHumanState_SwordLocomotion : public UPlayerHumanState_Sword_BaseState
{
	GENERATED_BODY()


/**
 * Properties
 */

public:
protected:
private:

/**
 * Functions
 */

public:
	UPlayerHumanState_SwordLocomotion();
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void TickState(float p_DeltaTime) override;

	virtual void BindToCharacterDelegates();

protected:
private:
	UFUNCTION()
		void HandleDelegate_CharacterPlayerBase_MoveUp(float p_Value);
	UFUNCTION()
		void HandleDelegate_CharacterPlayerBase_MoveRight(float p_Value);
};
