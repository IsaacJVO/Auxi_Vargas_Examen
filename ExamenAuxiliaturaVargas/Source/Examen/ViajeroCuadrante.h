
#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "ViajeroCuadrante.generated.h"

/**
 * 
 */
UCLASS()
class EXAMEN_API AViajeroCuadrante : public AMyActor
{
	GENERATED_BODY()

public:
    AViajeroCuadrante();

    virtual void Mover(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

    FVector CentroMovimiento;

    float Radio;
    float AnguloActual;
    float VelocidadAngular;
    float TiempoCambioAleatorio;
    float ContadorTiempo;

    void CambiarParametrosAleatorios();
	
};
