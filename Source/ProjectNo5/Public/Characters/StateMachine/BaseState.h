// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/DateTime.h"
#include "GameplayTagContainer.h"
#include "BaseState.generated.h"


class UComponent_StateMachine;

/**
 * 
 */

UCLASS(Abstract)
class PROJECTNO5_API UBaseState : public UObject
{
	GENERATED_BODY()



/**
 * Properties
 */

public:
	
protected:
	UPROPERTY()
		UComponent_StateMachine* m_StateMachineCompREF;

	FString m_StateID;
	FGameplayTagContainer m_StateTagContainer;
	FDateTime m_EnterStateTime;
	FDateTime m_ExitStateTime;

	float m_CooldownTime;
	bool b_IsInState;

private:



/**
 * Functions
 */

public:
	UBaseState();
	virtual void InitState(AActor* p_ActorREF, UComponent_StateMachine* p_StateMachineREF);

	virtual void EnterState();
	virtual void ExitState();
	virtual void TickState(float p_DeltaTime);

	// Get m_StateID
	const FString& GetStateID();

	// Get m_StateTagContainer
	const FGameplayTagContainer& GetStateTagContainer();

	// Duration from m_EnterStateTime to UtcNow
	float GetStateTime_LastEnterToNow();

	// Duration from m_ExitStateTime to UtcNow
	float GetStateTime_LastExitToNow();
	
	// Duration from m_EnterStateTime to m_ExitStateTime
	float GetStateTime_LastDuration();

	// Return true if state is in cooldown and cannot be entered
	bool CheckIsInCooldownTime();

	// Return true if p_HoldingTime > duration from m_ExitStateTime to UtcNow
	bool CheckForHoldingTime(float p_HoldingTime);

	// Set m_ExitStateTime to UtcNow. Used to reset exit time in combo states
	void SetExitStateTimeToNow();

protected:
	void ChangeState(const FString& p_NewStateID);
private:

};
