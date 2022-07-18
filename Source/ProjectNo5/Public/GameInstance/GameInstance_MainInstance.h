// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance_MainInstance.generated.h"


class USettingsManager;


/**
 * 
 */

UCLASS()
class PROJECTNO5_API UGameInstance_MainInstance : public UGameInstance
{
	GENERATED_BODY()



/**
 * Properties
 */

public:
	UPROPERTY(EditDefaultsOnly, Category = "Custom GameInstanceMainInstance")
		TSubclassOf<USettingsManager> m_Subclass_SettingsManager;

protected:
	UPROPERTY()
		USettingsManager* m_SettingsManager;
private:




/**
 * Functions
 */

public:
	UGameInstance_MainInstance();
	virtual void Init();

	// Get m_SettingsManagerREF
	USettingsManager* GetSettingsManager();

protected:
	virtual void OnStart();

private:
	// Create manager object instances: m_SettingManagerREF,  
	// Called in Init()
	void CreateManagerInstances();

};
