
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEstrategiaMovimiento.h"
#include "MyActor.generated.h"

UCLASS()
class EXAMEN_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();
    virtual void Tick(float DeltaTime) override;
    virtual void BeginPlay() override;

    void EstablecerEstrategiaMovimiento(TScriptInterface<IEstrategiaMovimiento> NuevaEstrategia);

    FVector ObtenerPosicion() const;

protected:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    TScriptInterface<IEstrategiaMovimiento> EstrategiaMovimiento;
};