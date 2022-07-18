// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SettingsManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraDistanceSettingValueChangedSignature, float, NewSettingValue);


/**
 * 
 */

UCLASS(Blueprintable)
class PROJECTNO5_API USettingsManager : public UObject
{
	GENERATED_BODY()


/**
 * Properties
 */

public:
	FOnCameraDistanceSettingValueChangedSignature m_Delegate_OnCameraDistanceChanged;
protected:

private:



/**
 * Functions
 */

public:
	USettingsManager();

	void UpdateSettingValue_CameraDistance(float p_AdditionValue);

protected:

private:
	float m_SettingValue_CameraDistance;
	const float c_CameraDistanceMultiplier = 0.5;
};
