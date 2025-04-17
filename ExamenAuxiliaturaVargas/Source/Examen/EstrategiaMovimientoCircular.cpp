// EstrategiaMovimientoCircular.cpp
#include "EstrategiaMovimientoCircular.h"

UEstrategiaMovimientoCircular::UEstrategiaMovimientoCircular()
{
    Radio = 200.0f;
    AnguloActual = 0.0f;
    VelocidadAngular = 1.0f;
    TiempoCambioAleatorio = 3.0f;
    ContadorTiempo = 0.0f;
    CentroMovimiento = FVector::ZeroVector;
}

void UEstrategiaMovimientoCircular::Inicializar(const FVector& PosicionInicial)
{
    CentroMovimiento = PosicionInicial;
    AnguloActual = FMath::RandRange(0.0f, 2.0f * PI);
}

FVector UEstrategiaMovimientoCircular::CalcularMovimiento(float DeltaTime, const FVector& PosicionActual)
{
    ContadorTiempo += DeltaTime;

    if (ContadorTiempo >= TiempoCambioAleatorio)
    {
        CambiarParametrosAleatorios();
        ContadorTiempo = 0.0f;
    }

   
    AnguloActual += VelocidadAngular * DeltaTime;
    if (AnguloActual > 2.0f * PI)
    {
        AnguloActual -= 2.0f * PI;
    }

    FVector NuevaPosicion;
    NuevaPosicion.X = CentroMovimiento.X + Radio * FMath::Cos(AnguloActual);
    NuevaPosicion.Y = CentroMovimiento.Y + Radio * FMath::Sin(AnguloActual);
    NuevaPosicion.Z = CentroMovimiento.Z;

    return NuevaPosicion;
}

void UEstrategiaMovimientoCircular::CambiarParametrosAleatorios()
{
    Radio = FMath::RandRange(100.0f, 300.0f);

    VelocidadAngular = FMath::RandRange(0.5f, 2.0f);

    float DesplazamientoX = FMath::RandRange(-50.0f, 50.0f);
    float DesplazamientoY = FMath::RandRange(-50.0f, 50.0f);

    CentroMovimiento.X += DesplazamientoX;
    CentroMovimiento.Y += DesplazamientoY;
}