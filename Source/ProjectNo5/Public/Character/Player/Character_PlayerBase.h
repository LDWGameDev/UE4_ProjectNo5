// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_PlayerBase.generated.h"


class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */

UCLASS()
class PROJECTNO5_API ACharacter_PlayerBase : public ACharacter
{
	GENERATED_BODY()


/**
 * Properties
 */

public:

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom PlayerBase Components")
		UCameraComponent* m_Camera_MainCam_01;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom PlayerBase Components")
		USpringArmComponent* m_SpringArm_MainCam_01;
private:



/**
 * Functions
 */

public:
	ACharacter_PlayerBase();

	// Input handling functions
	virtual void HandleInputAxis_MoveUp(float p_Value);
	virtual void HandleInputAxis_MoveRight(float p_Value);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
