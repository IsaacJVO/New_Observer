// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveSubscriptora1.h"
#include "Reloj.h"

// Sets default values
ANaveSubscriptora1::ANaveSubscriptora1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tiempo = "";

	//1
	MallaNave1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaNave1"));
	RootComponent = MallaNave1;
	//2
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_13.TwinStickUFO_13'"));
	MallaNave1->SetStaticMesh(malla.Object);


}

// Called when the game starts or when spawned
void ANaveSubscriptora1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveSubscriptora1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANaveSubscriptora1::EstablecerReloj(AReloj* _RelojSubscriptor)
{
	if (!_RelojSubscriptor) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("El reloj del subscriptor no existe"));
		return;
	}
	Reloj = _RelojSubscriptor;
	Reloj->Subscribirse(this);
}

void ANaveSubscriptora1::Actualizar(FString NuevoTiempo)
{
	SolicitarSubscriptor();
}

void ANaveSubscriptora1::SolicitarSubscriptor()
{
	if (!NaveSpawned) {
		Tiempo = Reloj->GetHora();
		if (Tiempo.Equals("10:00")) {
			if (UWorld* World = GetWorld())
			{
				// Define la clase de la nave subscriptora que quieres spawnar
				UClass* NaveSubscriptoraClass = ANaveSubscriptora1::StaticClass();
				// Define la posición y rotación en la que quieres spawnar la nave
				FVector SpawnLocation = FVector(-1600.0f, -450.0f, 200.0f); // Puedes ajustar esta posición según tus necesidades
				FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
				ANaveSubscriptora1* SpawnedNave = World->SpawnActor<ANaveSubscriptora1>(NaveSubscriptoraClass, SpawnLocation, SpawnRotation);
				NaveSpawned = true;
			}
		}
	}
}
void ANaveSubscriptora1::DestruirSubscripcion()
{
	Reloj->DeSubscribirse(this);
}

