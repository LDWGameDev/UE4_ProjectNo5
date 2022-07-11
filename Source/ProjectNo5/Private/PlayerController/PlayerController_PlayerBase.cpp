// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlayerController_PlayerBase.h"




/**
 * 
 */

APlayerController_PlayerBase::APlayerController_PlayerBase()
{

}



/**
 * Override function
 */

void APlayerController_PlayerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent == nullptr) return;
	InputComponent->BindAxis(FName(TEXT("MoveUp")), this, &APlayerController_PlayerBase::BindInputAxis_MoveUp);
	InputComponent->BindAxis(FName(TEXT("MoveRight")), this, &APlayerController_PlayerBase::BindInputAxis_MoveRight);
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
