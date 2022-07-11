// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/Character_PlayerHuman.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"



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
}




/**
 * Override functions
 */

void ACharacter_PlayerHuman::BeginPlay()
{
	Super::BeginPlay();

}

void ACharacter_PlayerHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




/**
 * Override functions
 */

void ACharacter_PlayerHuman::HandleInputAxis_MoveUp(float p_Value)
{

}

void ACharacter_PlayerHuman::HandleInputAxis_MoveRight(float p_Value)
{

}
