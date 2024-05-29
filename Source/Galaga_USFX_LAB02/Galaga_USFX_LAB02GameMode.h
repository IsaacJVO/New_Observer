// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB02GameMode.generated.h"

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_LAB02GameMode();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//**********************************************************************

protected:
	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class AReloj* Reloj;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class ANaveSubscriptora1* Sub1;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class ANaveSubscriptora2* Sub2;

public:
	float TimeDay;

	//**********************************************************************

public:

	UPROPERTY(VisibleAnywhere, Category = "FacadeNaves")
	class AFacadeNaves* FacadeNaves;

};