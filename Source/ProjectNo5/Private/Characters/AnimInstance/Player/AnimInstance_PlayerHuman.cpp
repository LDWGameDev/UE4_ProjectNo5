// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AnimInstance/Player/AnimInstance_PlayerHuman.h"

#include "Characters/Character/Player/Character_PlayerHuman.h"


/**
 * 
 */

UAnimInstance_PlayerHuman::UAnimInstance_PlayerHuman()
{
	m_NormalizedMovingSpeed = 0.0f;
	m_MovingDirectionAngle = 0.0f;
}


/**
 * Override functions
 */

void UAnimInstance_PlayerHuman::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	m_CharacterPlayerHumanREF = Cast<ACharacter_PlayerHuman>(this->TryGetPawnOwner());
}

void UAnimInstance_PlayerHuman::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (m_CharacterPlayerHumanREF == nullptr) return;
	m_NormalizedMovingSpeed = m_CharacterPlayerHumanREF->GetVelocity().Size() / c_DefaultMaxRunSpeed;
	m_MovingDirectionAngle = this->CalculateDirection(m_CharacterPlayerHumanREF->GetVelocity(), m_CharacterPlayerHumanREF->GetActorRotation());
}
