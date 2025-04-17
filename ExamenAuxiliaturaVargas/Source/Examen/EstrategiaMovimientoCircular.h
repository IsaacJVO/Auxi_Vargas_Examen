#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEstrategiaMovimiento.h"
#include "EstrategiaMovimientoCircular.generated.h"

UCLASS()
class EXAMEN_API UEstrategiaMovimientoCircular : public UObject, public IEstrategiaMovimiento
{
    GENERATED_BODY()

public:
    UEstrategiaMovimientoCircular();

    virtual FVector CalcularMovimiento(float DeltaTime, const FVector& PosicionActual) override;
    virtual void Inicializar(const FVector& PosicionInicial) override;

    void CambiarParametrosAleatorios();

private:
    FVector CentroMovimiento;

    float Radio;

    float AnguloActual;

    float VelocidadAngular;

    float TiempoCambioAleatorio;

    float ContadorTiempo;
};