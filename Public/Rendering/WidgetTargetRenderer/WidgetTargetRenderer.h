// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UMG.h"
#include "Widgets/SWidget.h"
#include "Slate/WidgetRenderer.h"
#include "Blueprint/UserWidget.h"

#include "WidgetTargetRenderer.generated.h"

/**
 * Renders an assigned Widget to a render target image, should be eventually integrated into it's own UI widget class.
 */
UCLASS(BlueprintType)
class KEEPER_API UWidgetTargetRenderer final : public UObject
{
	GENERATED_BODY()
public:

	// Can't use C++ constructor directly so must call secondary set up function.
	UFUNCTION(BlueprintCallable, Category="Construction")
	void SetUp(UUserWidget* NewUserWidget, UTextureRenderTarget2D* NewTextureRenderTarget2D, FVector2D NewDrawSize, bool bUseGammaCorrection, bool bClearTargetBeforeRendering);
	
	UFUNCTION(BlueprintCallable, Category="Rendering")
	void DrawWidgetToTarget();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UUserWidget* UserWidget = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTextureRenderTarget2D* TextureRenderTarget2D = nullptr;

	FWidgetRenderer WidgetRenderer; // variable instead of a pointer so the variable can take advantage of RAII and avoid a memory leak.
	FVector2D DrawSize; // Preload the draw size with Set Up
};
