#include "EstrategiaMovimientoAleatorio.h"

UEstrategiaMovimientoAleatorio::UEstrategiaMovimientoAleatorio()
{
    TiempoCambioDireccion = 2.0f;
    ContadorTiempo = 0.0f;
    DireccionActual = FVector::ZeroVector;
    LimiteMovimiento = 1000.0f;
    Velocidad = 100.0f;
}

void UEstrategiaMovimientoAleatorio::Inicializar(const FVector& PosicionInicial)
{
    GenerarDireccionAleatoria();
}

FVector UEstrategiaMovimientoAleatorio::CalcularMovimiento(float DeltaTime, const FVector& PosicionActual)
{
    ContadorTiempo += DeltaTime;

    if (ContadorTiempo >= TiempoCambioDireccion)
    {
        GenerarDireccionAleatoria();
        ContadorTiempo = 0.0f;
    }

    FVector NuevaPosicion = PosicionActual + (DireccionActual * Velocidad * DeltaTime);

    if (FMath::Abs(NuevaPosicion.X) > LimiteMovimiento ||
        FMath::Abs(NuevaPosicion.Y) > LimiteMovimiento)
    {
        DireccionActual = -DireccionActual;
        NuevaPosicion = PosicionActual + (DireccionActual * Velocidad * DeltaTime);
    }

    return NuevaPosicion;
}

void UEstrategiaMovimientoAleatorio::GenerarDireccionAleatoria()
{
    float AnguloAleatorio = FMath::RandRange(0.0f, 2.0f * PI);

    DireccionActual.X = FMath::Cos(AnguloAleatorio);
    DireccionActual.Y = FMath::Sin(AnguloAleatorio);
    DireccionActual.Z = 0.0f;

    DireccionActual.Normalize();
}