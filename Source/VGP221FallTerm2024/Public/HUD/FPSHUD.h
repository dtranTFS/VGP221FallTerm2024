// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GUI/Slate/SSettingsWidget.h"
#include "Engine/Canvas.h"
#include "GUI/FPSUserWidget.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FALLTERM2024_API AFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// 1. HUD method of making UI
	virtual void DrawHUD() override;

	// 2. Slates method of making UI
	TSharedPtr<class SSettingsWidget> settingsWidget;
	TSharedPtr<class SWidget> settingsWidgetContainer;

	void ShowSettingsMenu();
	void RemoveSettingsMenu();
	
	// 3. UMG method of making UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UFPSUserWidget> startingGameWidget;

	UPROPERTY()
	UFPSUserWidget* gameWidgetContainer;

	void ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget);

protected:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;
};
