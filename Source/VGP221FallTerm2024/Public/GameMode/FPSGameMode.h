// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FALLTERM2024_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;

};
