// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_StateMachine.generated.h"

class UBaseState;

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTNO5_API UComponent_StateMachine : public UActorComponent
{
	GENERATED_BODY()


/**
 * Properties
 */

public:
	FString m_DefaultStateIDWhenFail;
	int32 m_HistoryStateLength;
protected:
private:
	TArray<UBaseState*> m_StateList;
	TArray<UBaseState*> m_HistoryStateList;
	UBaseState* m_CurrentState;
	bool b_IsActive;


/**
 * Functions
 */

public:	
	UComponent_StateMachine();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Get m_StateList
	TArray<UBaseState*>* GetStateList();

	// Get m_HistoryStateList
	TArray<UBaseState*>* GetHistoryStateList();

	// Activate or deactivate state machine
	void ActivateStateMachine(bool p_DoActivate, const FString& p_StartStateID);

	// Change to new state in m_StateList that matches p_NewStateID
	void ChangeState(const FString& p_NewStateID);


protected:
	virtual void BeginPlay() override;

private:	
	void AddStateToHistory(UBaseState* p_HistoryState);
	void ChangeToDefaultState();
};
