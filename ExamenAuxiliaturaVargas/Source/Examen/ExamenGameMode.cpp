//GAMEMODE 

#include "ExamenGameMode.h"
#include "ViajeroErrante.h"
#include "ViajeroCuadrante.h"
#include "Engine/World.h"

AExamenGameMode::AExamenGameMode()
{
    ViajeroErranteInstancia = nullptr;
    ViajeroCuadranteInstancia = nullptr;
}

void AExamenGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnViajeros();
}

void AExamenGameMode::SpawnViajeros()
{
    UWorld* World = GetWorld();
    if (World)
    {


        //VIAJERO ERRANTE HACER APARECER
        FVector ViajeroErranteLocation(1430.0f, 2010.0f, 40.0f);
        FRotator ViajeroErranteRotation(0.0f, 0.0f, 0.0f);
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

        ViajeroErranteInstancia = World->SpawnActor<AViajeroErrante>(
            AViajeroErrante::StaticClass(),
            ViajeroErranteLocation,
            ViajeroErranteRotation,
            SpawnParams
        );

        if (ViajeroErranteInstancia)
        {
            UE_LOG(LogTemp, Warning, TEXT("Viajero Errante spawmeado en X=%f Y=%f Z=%f"),
                ViajeroErranteLocation.X, ViajeroErranteLocation.Y, ViajeroErranteLocation.Z);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo spawmear el Viajero Errante"));
        }





        //VIAJERO CUADRANTE SPAWMEAR
        FVector ViajeroCuadranteLocation(1430.0f, 1180.0f, 40.0f);
        FRotator ViajeroCuadranteRotation(0.0f, 0.0f, 0.0f);

        ViajeroCuadranteInstancia = World->SpawnActor<AViajeroCuadrante>(
            AViajeroCuadrante::StaticClass(),
            ViajeroCuadranteLocation,
            ViajeroCuadranteRotation,
            SpawnParams
        );

        if (ViajeroCuadranteInstancia)
        {
            UE_LOG(LogTemp, Warning, TEXT("Viajero Cuadrante spawmeado en X=%f Y=%f Z=%f"),
                ViajeroCuadranteLocation.X, ViajeroCuadranteLocation.Y, ViajeroCuadranteLocation.Z);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo spawmear el Viajero Cuadrante"));
        }
    }
}