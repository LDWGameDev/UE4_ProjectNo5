// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Character/Player/Character_PlayerBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Characters/StateMachine/Component_StateMachine.h"
#include "System/Settings/SettingsManager.h"
#include "GameInstance/GameInstance_MainInstance.h"


/**
 * 
 */

ACharacter_PlayerBase::ACharacter_PlayerBase()
{
	// Character PlayerBase defaults
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// SpringArm defaults
	m_SpringArm_MainCam_01 = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Main Cam 01"));
	m_SpringArm_MainCam_01->SetupAttachment(RootComponent);

	// CameraComponent defaults
	m_Camera_MainCam_01 = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent Main Cam 01"));
	m_Camera_MainCam_01->SetupAttachment(m_SpringArm_MainCam_01);

	// SkeletalMesh defaults
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// StateMachine defaults
	m_StateMachine_01 = CreateDefaultSubobject<UComponent_StateMachine>(TEXT("StateMachine 01"));
}





/**
 * Override functions
 */

void ACharacter_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
	HandleOnPossessed();
}

void ACharacter_PlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}





/**
 * Public member functions
 */

void ACharacter_PlayerBase::HandleInputAxis_MoveUp(float p_Value)
{
	if (m_DelegateCharacterPlayerBase_MoveUp.IsBound()) m_DelegateCharacterPlayerBase_MoveUp.Broadcast(p_Value);
}

void ACharacter_PlayerBase::HandleInputAxis_MoveRight(float p_Value)
{
	if (m_DelegateCharacterPlayerBase_MoveRight.IsBound()) m_DelegateCharacterPlayerBase_MoveRight.Broadcast(p_Value);
}

void ACharacter_PlayerBase::HandleOnPossessed()
{
	UGameInstance_MainInstance* MainInstance = Cast<UGameInstance_MainInstance>(GetWorld()->GetGameInstance());
	if (MainInstance != nullptr && MainInstance->GetSettingsManager() != nullptr)
	{
		MainInstance->GetSettingsManager()->m_Delegate_OnCameraDistanceChanged.AddDynamic(this, &ACharacter_PlayerBase::HandleDelegate_OnCameraDistanceSettingValueChanged);
	}
}

void ACharacter_PlayerBase::HandleOnUnpossessed()
{
	if (m_StateMachine_01 != nullptr) m_StateMachine_01->ActivateStateMachine(false, TEXT(""));
	UGameInstance_MainInstance* MainInstance = Cast<UGameInstance_MainInstance>(GetWorld()->GetGameInstance());
	if (MainInstance != nullptr && MainInstance->GetSettingsManager() != nullptr)
	{
		MainInstance->GetSettingsManager()->m_Delegate_OnCameraDistanceChanged.RemoveDynamic(this, &ACharacter_PlayerBase::HandleDelegate_OnCameraDistanceSettingValueChanged);
	}
}

void ACharacter_PlayerBase::MoveCharacterUp(float p_MoveUpValue)
{
	if (m_Camera_MainCam_01 == nullptr) return;
	FRotator ControllerRotation = m_Camera_MainCam_01->GetComponentRotation();
	ControllerRotation.Pitch = 0.0f;
	ControllerRotation.Roll = 0.0f;
	FVector ControllerUpVector = UKismetMathLibrary::GetForwardVector(ControllerRotation);
	AddMovementInput(ControllerUpVector, p_MoveUpValue);
}

void ACharacter_PlayerBase::MoveCharacterRight(float p_MoveRightValue)
{
	if (m_Camera_MainCam_01 == nullptr) return;
	FRotator ControllerRotation = m_Camera_MainCam_01->GetComponentRotation();
	ControllerRotation.Pitch = 0.0f;
	ControllerRotation.Roll = 0.0f;
	FVector ControllerRightVector = UKismetMathLibrary::GetRightVector(ControllerRotation);
	AddMovementInput(ControllerRightVector, p_MoveRightValue);
}




/**
 * Private member functions
 */

void ACharacter_PlayerBase::HandleDelegate_OnCameraDistanceSettingValueChanged(float p_NewCameraDistanceSettingValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CharacterPlayerBase HandleDelegate_CameraValueChanged()"));
}
