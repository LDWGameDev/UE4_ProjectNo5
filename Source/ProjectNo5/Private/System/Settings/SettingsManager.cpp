// Fill out your copyright notice in the Description page of Project Settings.


#include "System/Settings/SettingsManager.h"



/**
 * 
 */

USettingsManager::USettingsManager()
{
	m_SettingValue_CameraDistance = 5.0f;
}




/**
 * Public member functions
 */

void USettingsManager::UpdateSettingValue_CameraDistance(float p_AdditionValue)
{
	float TempValue = m_SettingValue_CameraDistance + p_AdditionValue * c_CameraDistanceMultiplier;
	TempValue = FMath::Clamp(TempValue, 0.0f, 10.0f);
	if (m_SettingValue_CameraDistance != TempValue)
	{
		m_SettingValue_CameraDistance = TempValue;
		if (m_Delegate_OnCameraDistanceChanged.IsBound()) m_Delegate_OnCameraDistanceChanged.Broadcast(m_SettingValue_CameraDistance);
		UE_LOG(LogTemp, Warning, TEXT("SettingsManager camera distance value: %f"), m_SettingValue_CameraDistance);
	}
}
