
#include "ViajeroErrante.h"
#include "kismet/KismetMaterialLibrary.h"

AViajeroErrante::AViajeroErrante()
{
    TiempoCambioDireccion = 2.0f;
    ContadorTiempo = 0.0f;
    DireccionActual = FVector::ZeroVector;
    LimiteMovimiento = 1000.0f;
}

void AViajeroErrante::Mover(float DeltaTime)
{
    ContadorTiempo += DeltaTime;

    if (ContadorTiempo >= TiempoCambioDireccion)
    {
        GenerarDireccionAleatoria();
        ContadorTiempo = 0.0f;
    }

    FVector NuevaUbicacion = GetActorLocation() + (DireccionActual * Velocidad * DeltaTime);

    if (FMath::Abs(NuevaUbicacion.X) > LimiteMovimiento ||
        FMath::Abs(NuevaUbicacion.Y) > LimiteMovimiento)
    {
        DireccionActual = -DireccionActual;
        NuevaUbicacion = GetActorLocation() + (DireccionActual * Velocidad * DeltaTime);
    }

    SetActorLocation(NuevaUbicacion);

}

void AViajeroErrante::BeginPlay()
{

    Super::BeginPlay();
    GenerarDireccionAleatoria();

}

void AViajeroErrante::GenerarDireccionAleatoria()
{
    float AnguloAleatorio = FMath::RandRange(0.0f, 2.0f * PI);

    DireccionActual.X = FMath::Cos(AnguloAleatorio);
    DireccionActual.Y = FMath::Sin(AnguloAleatorio);
    DireccionActual.Z = 0.0f;

    DireccionActual.Normalize();
}
