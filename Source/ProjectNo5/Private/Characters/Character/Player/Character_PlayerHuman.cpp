// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Character/Player/Character_PlayerHuman.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Characters/StateMachine/Component_StateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/AnimInstance/Player/AnimInstance_PlayerHuman.h"
#include "Characters/StateMachine/Player/PlayerHumanState_SwordLocomotion.h"

/**
 * 
 */

ACharacter_PlayerHuman::ACharacter_PlayerHuman()
{
	// Character PlayerHuman defaults

	// CapsuleComponent defaults
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// SkeletalMesh defaults
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -96.0f));

	// SpringArm defaults
	m_SpringArm_MainCam_01->TargetArmLength = 1200.0f;

	// CameraComponent defaults
	m_Camera_MainCam_01->FieldOfView = 60.0f;

	// StateMachine default
	m_StateMachine_01->m_DefaultStateIDWhenFail = TEXT("PlayerHumanState_Locomotion");

	// CharacterMovementComponent defaults
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
}





/**
 * Override functions
 */

void ACharacter_PlayerHuman::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (GetMesh() != nullptr) m_AnimInstancePlayerHumanREF = Cast<UAnimInstance_PlayerHuman>(GetMesh()->GetAnimInstance());
	CreateStateInstances();
}

void ACharacter_PlayerHuman::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacter_PlayerHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacter_PlayerHuman::HandleOnPossessed()
{
	Super::HandleOnPossessed();
	FTimerHandle TimerHandle_DelayOnPossessed;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_DelayOnPossessed, [&]()
		{
			if (m_StateMachine_01 != nullptr)
			{
				m_StateMachine_01->ActivateStateMachine(true, TEXT("PlayerHumanState_SwordLocomotion"));
			}
		}, 0.5f, false);
}

void ACharacter_PlayerHuman::HandleOnUnpossessed()
{
	Super::HandleOnUnpossessed();
}




/**
 * Override functions
 */

void ACharacter_PlayerHuman::HandleInputAxis_MoveUp(float p_Value)
{
	Super::HandleInputAxis_MoveUp(p_Value);
}

void ACharacter_PlayerHuman::HandleInputAxis_MoveRight(float p_Value)
{
	Super::HandleInputAxis_MoveRight(p_Value);
}




/**
 * Private member functions
 */

void ACharacter_PlayerHuman::CreateStateInstances()
{
	if (m_StateMachine_01 == nullptr) return;
	auto StateList = m_StateMachine_01->GetStateList();
	if (StateList == nullptr) return;
	
	StateList->Reserve(1);
	m_SwordLocomotionState = NewObject<UPlayerHumanState_SwordLocomotion>();
	m_SwordLocomotionState->InitState(this, m_StateMachine_01);
	StateList->Add(m_SwordLocomotionState);
}










void ACharacter_PlayerHuman::TestFunction(int p_CommandID)
{
	switch (p_CommandID)
	{
	case 0:
	{
		m_StateMachine_01->ChangeState(TEXT("PlayerHumanState_SwordLocomotion"));
		break;
	}
	case 1:
	{
		m_StateMachine_01->ChangeState(TEXT("PlayerHumanState_SwordLocomotion_NoNo"));
		break;
	}
	}
}
