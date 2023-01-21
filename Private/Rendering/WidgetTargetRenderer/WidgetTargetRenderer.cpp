// Fill out your copyright notice in the Description page of Project Settings.


#include "Rendering/WidgetTargetRenderer/WidgetTargetRenderer.h"


void UWidgetTargetRenderer::SetUp(UUserWidget* NewUserWidget, UTextureRenderTarget2D* NewTextureRenderTarget2D, FVector2D NewDrawSize, bool bUseGammaCorrection, bool bClearTargetBeforeRendering)
{
	this->DrawSize = NewDrawSize;
	this->UserWidget = NewUserWidget; // store the reference
	this->TextureRenderTarget2D = NewTextureRenderTarget2D;
	this->WidgetRenderer = FWidgetRenderer(bUseGammaCorrection, bClearTargetBeforeRendering);

}

// need to make safety checking version

void UWidgetTargetRenderer::DrawWidgetToTarget()
{
	this->WidgetRenderer.DrawWidget(this->TextureRenderTarget2D, this->UserWidget->TakeWidget(), DrawSize, 0.0f);
}
