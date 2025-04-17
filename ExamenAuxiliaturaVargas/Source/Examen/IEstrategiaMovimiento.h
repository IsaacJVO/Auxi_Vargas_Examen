#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstrategiaMovimientO.h"

UINTERFACE(MinimalAPI)
class UEstrategiaMovimiento : public UInterface
{
    GENERATED_BODY()
};

class IEstrategiaMovimiento
{
    GENERATED_BODY()

public:
    virtual FVector CalcularMovimiento(float DeltaTime, FVector PosicionActual) = 0;
};