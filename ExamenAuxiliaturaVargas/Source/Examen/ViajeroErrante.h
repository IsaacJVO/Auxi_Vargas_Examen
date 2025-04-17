
#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "ViajeroErrante.generated.h"

/**
 * 
 */
UCLASS()
class EXAMEN_API AViajeroErrante : public AMyActor
{
	GENERATED_BODY()

public:
    AViajeroErrante();

    virtual void Mover(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

    float TiempoCambioDireccion;

    float ContadorTiempo;

    FVector DireccionActual;

    float LimiteMovimiento;

    void GenerarDireccionAleatoria();
	
};
