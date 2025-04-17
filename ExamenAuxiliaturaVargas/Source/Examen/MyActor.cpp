#include "MyActor.h"
#include "IEstrategiaMovimiento.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    if (EstrategiaMovimiento)
    {
        UE_LOG(LogTemp, Log, TEXT("Estrategia de movimiento inicializada"));
    }
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (EstrategiaMovimiento)
    {
        FVector NuevaPosicion = IEstrategiaMovimiento::Execute_CalcularMovimiento
        (
            EstrategiaMovimiento.GetObject(),
            DeltaTime,
            GetActorLocation()
        );

        SetActorLocation(NuevaPosicion);
    }
}

void AMyActor::EstablecerEstrategiaMovimiento(TScriptInterface<IEstrategiaMovimiento> NuevaEstrategia)
{
    EstrategiaMovimiento = NuevaEstrategia;

    if (EstrategiaMovimiento)
    {
        UE_LOG(LogTemp, Log, TEXT("Estrategia de movimiento inicializada"));
    }
}

FVector AMyActor::ObtenerPosicion() const
{
    return GetActorLocation();
}
3. Corrige la llamada a CalcularMovimiento
El método Execute_CalcularMovimiento es generado automáticamente por Unreal Engine para funciones marcadas como BlueprintNativeEvent o BlueprintImplementableEvent en una interfaz.Sin embargo, la forma en que lo estás llamando parece correcta, pero asegúrate de que :

El método CalcularMovimiento está definido en la interfaz como se mostró arriba.
La clase que implementa IEstrategiaMovimiento(la que asignas a EstrategiaMovimiento) tiene una imp