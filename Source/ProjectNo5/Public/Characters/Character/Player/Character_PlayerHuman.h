// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_PlayerBase.h"
#include "Character_PlayerHuman.generated.h"


class UAnimInstance_PlayerHuman;
class UPlayerHumanState_SwordLocomotion;

/**
 * 
 */

UCLASS()
class PROJECTNO5_API ACharacter_PlayerHuman : public ACharacter_PlayerBase
{
	GENERATED_BODY()
	

/**
 * Properties
 */
public:
	// State instances. Derived class of PlayerHumanBaseState
	// Creates and sets values in CreateStateInstances()
	UPROPERTY()
		UPlayerHumanState_SwordLocomotion* m_SwordLocomotionState;

protected:
	// AnimInstance reference. Set reference value in PostInitializeComponents()
	UPROPERTY()
		UAnimInstance_PlayerHuman* m_AnimInstancePlayerHumanREF;
private:



/**
 * Functions
 */
public:
	ACharacter_PlayerHuman();
	virtual void PostInitializeComponents();
	virtual void Tick(float DeltaTime) override;

	// Override functions of Character_PlayerBase
	virtual void HandleInputAxis_MoveUp(float p_Value) override;
	virtual void HandleInputAxis_MoveRight(float p_Value) override;

protected:
	virtual void BeginPlay() override;

	// Override CharacterPlayerBase functions
	virtual void HandleOnPossessed() override;
	virtual void HandleOnUnpossessed() override;

private:
	// Create state instances of this character. Called in PostInitializeComponents()
	void CreateStateInstances();

public:
	UFUNCTION(BlueprintCallable)
		void TestFunction(int p_CommandID);
};
