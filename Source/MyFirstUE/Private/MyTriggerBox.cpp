// Fill out your copyright notice in the Description page of Project Settings.

#include "CarPawn.h"
#include "MyTriggerBox.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerBox::OnEndOverlap);
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ACarPawn* carPawn = CastChecked<ACarPawn>(OtherActor);
	if (carPawn != nullptr)
	{
		currentCars++;
		if (currentCars >= totalCarsToWin) {
			UE_LOG(LogTemp, Warning, TEXT("You won!!!! <3"));
		}
	}
}

void AMyTriggerBox::OnEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	ACarPawn* carPawn = CastChecked<ACarPawn>(OtherActor);
	if (carPawn != nullptr)
	{
		currentCars--;
	}
}
