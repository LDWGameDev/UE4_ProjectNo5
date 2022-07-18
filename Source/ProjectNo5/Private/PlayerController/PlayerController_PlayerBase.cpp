// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlayerController_PlayerBase.h"

#include "System/Settings/SettingsManager.h"
#include "GameInstance/GameInstance_MainInstance.h"



/**
 * 
 */

APlayerController_PlayerBase::APlayerController_PlayerBase()
{

}



/**
 * Override function
 */

void APlayerController_PlayerBase::BeginPlay()
{
	Super::BeginPlay();
	UGameInstance_MainInstance* MainInstance = Cast<UGameInstance_MainInstance>(GetWorld()->GetGameInstance());
	if (MainInstance != nullptr) m_SettingManagerREF = MainInstance->GetSettingsManager();
}


void APlayerController_PlayerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent == nullptr) return;
	InputComponent->BindAxis(FName(TEXT("MoveUp")), this, &APlayerController_PlayerBase::BindInputAxis_MoveUp);
	InputComponent->BindAxis(FName(TEXT("MoveRight")), this, &APlayerController_PlayerBase::BindInputAxis_MoveRight);
	InputComponent->BindAxis(FName(TEXT("MiddleMouse")), this, &APlayerController_PlayerBase::BindInputAxis_MiddleMouseScroll);
}



/**
 * Protected member functions
 */

void APlayerController_PlayerBase::BindInputAxis_MoveUp(float p_Value)
{

}

void APlayerController_PlayerBase::BindInputAxis_MoveRight(float p_Value)
{

}

void APlayerController_PlayerBase::BindInputAxis_MiddleMouseScroll(float p_Value)
{

}
