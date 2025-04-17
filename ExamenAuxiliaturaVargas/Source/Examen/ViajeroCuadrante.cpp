
#include "ViajeroCuadrante.h"

AViajeroCuadrante::AViajeroCuadrante()
{
    CentroMovimiento = FVector::ZeroVector;
    Radio = 200.0f;
    AnguloActual = 0.0f;
    VelocidadAngular = 1.0f;
    TiempoCambioAleatorio = 3.0f;
    ContadorTiempo = 0.0f;
}

void AViajeroCuadrante::Mover(float DeltaTime)
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

    FVector NuevaUbicacion;
    NuevaUbicacion.X = CentroMovimiento.X + Radio * FMath::Cos(AnguloActual);
    NuevaUbicacion.Y = CentroMovimiento.Y + Radio * FMath::Sin(AnguloActual);
    NuevaUbicacion.Z = CentroMovimiento.Z;

    SetActorLocation(NuevaUbicacion);
}

void AViajeroCuadrante::BeginPlay()
{
    Super::BeginPlay();

    CentroMovimiento = GetActorLocation();

    AnguloActual = FMath::RandRange(0.0f, 2.0f * PI);
}

void AViajeroCuadrante::CambiarParametrosAleatorios()
{
    Radio = FMath::RandRange(100.0f, 300.0f);

    VelocidadAngular = FMath::RandRange(0.5f, 2.0f);

    float DesplazamientoX = FMath::RandRange(-50.0f, 50.0f);
    float DesplazamientoY = FMath::RandRange(-50.0f, 50.0f);

    CentroMovimiento.X += DesplazamientoX;
    CentroMovimiento.Y += DesplazamientoY;
}
