// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstance/Player/AnimInstance_PlayerBase.h"
#include "AnimInstance_PlayerHuman.generated.h"


class ACharacter_PlayerHuman;

/**
 * 
 */
UCLASS()
class PROJECTNO5_API UAnimInstance_PlayerHuman : public UAnimInstance_PlayerBase
{
	GENERATED_BODY()
	

/**
 * Properties
 */

public:
	// Character normalized moving speed based on c_DefaultMaxRunSpeed
	UPROPERTY(BlueprintReadOnly, Category = "Custom AnimInstancePlayerHuman")
		float m_NormalizedMovingSpeed;

	// Angle between character facing direction and velocity vector
	UPROPERTY(BlueprintReadOnly, Category = "Custom AnimInstancePlayerHuman")
		float m_MovingDirectionAngle;

protected:
	// Character owner CharacterPlayerHuman reference
	// Set reference value in NativeInitializeAnimation()
	UPROPERTY()
		ACharacter_PlayerHuman* m_CharacterPlayerHumanREF;
private:
	// Default run speed of character
	const float c_DefaultMaxRunSpeed = 600.0f;


/**
 * Functions
 */

public:
	UAnimInstance_PlayerHuman();

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

private:

};
