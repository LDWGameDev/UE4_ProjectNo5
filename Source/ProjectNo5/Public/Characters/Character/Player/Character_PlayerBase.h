// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_PlayerBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterPlayerBase_MoveUpSignature, float, MoveValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterPlayerBase_MoveRightSignature, float, MoveValue);

class UCameraComponent;
class USpringArmComponent;
class UComponent_StateMachine;


/**
 * 
 */

UCLASS(Abstract)
class PROJECTNO5_API ACharacter_PlayerBase : public ACharacter
{
	GENERATED_BODY()


/**
 * Properties
 */

public:
	FOnCharacterPlayerBase_MoveUpSignature m_DelegateCharacterPlayerBase_MoveUp;
	FOnCharacterPlayerBase_MoveRightSignature m_DelegateCharacterPlayerBase_MoveRight;

protected:
	// Character components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom PlayerBase Components")
		UCameraComponent* m_Camera_MainCam_01;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom PlayerBase Components")
		USpringArmComponent* m_SpringArm_MainCam_01;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cusotm PlayerBase Components")
		UComponent_StateMachine* m_StateMachine_01;

private:



/**
 * Functions
 */

public:
	ACharacter_PlayerBase();
	virtual void Tick(float DeltaTime) override;

	// Input handling functions. Called in PlayerController
	virtual void HandleInputAxis_MoveUp(float p_Value);
	virtual void HandleInputAxis_MoveRight(float p_Value);

	// Moves character based on input value. Called in specific state
	void MoveCharacterUp(float p_MoveUpValue);
	void MoveCharacterRight(float p_MoveRightValue);

protected:
	virtual void BeginPlay() override;

	// Custom possess and unpossess handling functions
	virtual void HandleOnPossessed();
	virtual void HandleOnUnpossessed();
	
	// Binds to delegate m_Delegate_OnCameraDistanceSettingValueChanged of SettingsManager.
	// Changes m_SpringArm_MainCam_01 based on that setting value
	// Binds in HandleOnPossessed() and unbinds in HandleOnUnPossessed()
	UFUNCTION()
		virtual void HandleDelegate_OnCameraDistanceSettingValueChanged(float p_NewCameraDistanceSettingValue);

private:	

};
