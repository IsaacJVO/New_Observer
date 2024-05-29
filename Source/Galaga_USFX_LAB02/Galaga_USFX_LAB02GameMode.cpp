#include "Galaga_USFX_LAB02GameMode.h"
#include "Galaga_USFX_LAB02Pawn.h"
#include "NaveSubscriptora1.h"
#include "NaveSubscriptora2.h"
#include "Reloj.h"
#include "FacadeNaves.h"


AGalaga_USFX_LAB02GameMode::AGalaga_USFX_LAB02GameMode()
{
    DefaultPawnClass = AGalaga_USFX_LAB02Pawn::StaticClass();
    TimeDay = 0.0f;

}

void AGalaga_USFX_LAB02GameMode::BeginPlay()
{
    Super::BeginPlay();

    FacadeNaves = GetWorld()->SpawnActor<AFacadeNaves>(AFacadeNaves::StaticClass());

    FacadeNaves->SPAWN_NAVES_ENEMIGAS();
    FacadeNaves->SpawnPowerUpVelocidad();

    //**********************************************************************

    Reloj = GetWorld()->SpawnActor<AReloj>(AReloj::StaticClass());
    if (Reloj)
    {
        Sub1 = GetWorld()->SpawnActor<ANaveSubscriptora1>(ANaveSubscriptora1::StaticClass());
        Sub1->EstablecerReloj(Reloj);
        Sub2 = GetWorld()->SpawnActor<ANaveSubscriptora2>(ANaveSubscriptora2::StaticClass());
        Sub2->EstablecerReloj(Reloj);
    }
}

void AGalaga_USFX_LAB02GameMode::Tick(float DeltaTime)
{
    TimeDay += DeltaTime;
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Hora de Llegada %f"), TimeDay));

    if (TimeDay >= 10.0f) {
        Reloj->SetHora("10:00");
    }

    if (TimeDay >= 20.0f) {
        Sub2->DestruirSubscripcion();
        TimeDay = 0.0f; // Reinicia el tiempo
    }
}