// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/Character_PlayerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"



/**
 * 
 */

ACharacter_PlayerBase::ACharacter_PlayerBase()
{
	// Character PlayerBase defaults
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm defaults
	m_SpringArm_MainCam_01 = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Main Cam 01"));
	m_SpringArm_MainCam_01->SetupAttachment(RootComponent);

	// CameraComponent defaults
	m_Camera_MainCam_01 = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent Main Cam 01"));
	m_Camera_MainCam_01->SetupAttachment(m_SpringArm_MainCam_01);

	// SkeletalMesh defaults
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
}






/**
 * Override functions
 */

void ACharacter_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacter_PlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacter_PlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}



/**
 * Public member functions
 */

void ACharacter_PlayerBase::HandleInputAxis_MoveUp(float p_Value)
{

}

void ACharacter_PlayerBase::HandleInputAxis_MoveRight(float p_Value)
{

}

