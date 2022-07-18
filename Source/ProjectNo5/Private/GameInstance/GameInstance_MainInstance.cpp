// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/GameInstance_MainInstance.h"

#include "System/Settings/SettingsManager.h"



/**
 * 
 */

UGameInstance_MainInstance::UGameInstance_MainInstance()
{

}




/**
 * Public member functions
 */

void UGameInstance_MainInstance::Init()
{
	Super::Init();
	CreateManagerInstances();
}

void UGameInstance_MainInstance::OnStart()
{
	Super::OnStart();
}




/**
 * Public member function
 */

USettingsManager* UGameInstance_MainInstance::GetSettingsManager()
{
	return m_SettingsManager;
}





/**
 * Private member functions
 */

void UGameInstance_MainInstance::CreateManagerInstances()
{
	if (m_Subclass_SettingsManager != nullptr) m_SettingsManager = NewObject<USettingsManager>(m_Subclass_SettingsManager);
}

