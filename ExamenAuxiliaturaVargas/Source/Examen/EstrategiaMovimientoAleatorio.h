// EstrategiaMovimientoAleatorio.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEstrategiaMovimiento.h"
#include "EstrategiaMovimientoAleatorio.generated.h"

UCLASS()
class EXAMEN_API UEstrategiaMovimientoAleatorio : public UObject, public IEstrategiaMovimiento
{
    GENERATED_BODY()

public:
    UEstrategiaMovimientoAleatorio();

    virtual FVector CalcularMovimiento(float DeltaTime, const FVector& PosicionActual) override;
    virtual void Inicializar(const FVector& PosicionInicial) override;

    void GenerarDireccionAleatoria();

private:
    
    float TiempoCambioDireccion;

    float ContadorTiempo;

    FVector DireccionActual;

    float LimiteMovimiento;

    float Velocidad;
};