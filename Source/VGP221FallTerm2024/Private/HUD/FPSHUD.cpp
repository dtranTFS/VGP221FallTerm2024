// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"
#include "Widgets/SWeakWidget.h"

void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowGameMenu(startingGameWidget);
	//ShowSettingsMenu();
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	// 1. Calculate the center point on the screen
	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// 2. Set the crosshair pivot to the center
	float CrosshairHalfWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
	float CrosshairHalfHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
	FVector2D CrosshairDrawPos(Center.X - CrosshairHalfWidth, Center.Y - CrosshairHalfHeight);

	// 3. Draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPos, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AFPSHUD::ShowSettingsMenu()
{
	if (GEngine && GEngine->GameViewport) {
		settingsWidget = SNew(SSettingsWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(settingsWidgetContainer, SWeakWidget).PossiblyNullContent(settingsWidget.ToSharedRef()));

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AFPSHUD::RemoveSettingsMenu()
{
	if (GEngine && GEngine->GameViewport && settingsWidgetContainer.IsValid()) {
		GEngine->GameViewport->RemoveViewportWidgetContent(settingsWidgetContainer.ToSharedRef());

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AFPSHUD::ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget)
{
	if (gameWidgetContainer) {
		gameWidgetContainer->RemoveFromParent();
		gameWidgetContainer = nullptr;
	}

	if (newGameWidget) {
		gameWidgetContainer = CreateWidget<UFPSUserWidget>(GetWorld(), newGameWidget);
		gameWidgetContainer->AddToViewport();
	}
}
