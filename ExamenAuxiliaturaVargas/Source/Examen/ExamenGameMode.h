// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ExamenGameMode.generated.h"

class AViajeroErrante;
class AViajeroCuadrante;

UCLASS(minimalapi)
class AExamenGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AExamenGameMode();

    virtual void BeginPlay() override;

private:
    TSubclassOf<AViajeroErrante> ViajeroErranteClass;
    TSubclassOf<AViajeroCuadrante> ViajeroCuadranteClass;

    AViajeroErrante* ViajeroErranteInstancia;
    AViajeroCuadrante* ViajeroCuadranteInstancia;

    void SpawnViajeros();
};
