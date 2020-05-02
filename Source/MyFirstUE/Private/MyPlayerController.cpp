// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CarPawn.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/Pawn.h"


AMyPlayerController::AMyPlayerController()
{
	AutoReceiveInput = EAutoReceiveInput::Type::Player0;
	
}

void AMyPlayerController::BeginPlay()
{

	Super::BeginPlay();


	UWorld* world = GetWorld();
	
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(world, ACarPawn::StaticClass(), Actors);
	

	for (AActor* p: Actors) // Iteras por el array
	{	
		Pawns.Add(Cast<ACarPawn>(p));
	}

	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press1", EKeys::NumPadOne));
	InputComponent->BindAction("MyPlayerController_Press1", EInputEvent::IE_Pressed,this, &AMyPlayerController::Press1);
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press2", EKeys::NumPadTwo));
	InputComponent->BindAction("MyPlayerController_Press2", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press2);
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press3", EKeys::NumPadThree));
	InputComponent->BindAction("MyPlayerController_Press3", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press3);
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press4", EKeys::NumPadFour));
	InputComponent->BindAction("MyPlayerController_Press4", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press4);
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press5", EKeys::NumPadFive));
	InputComponent->BindAction("MyPlayerController_Press5", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press5);

}

void AMyPlayerController::Press1() 
{
	/* Cojo el controlador del player, hago UnPosses y poseo al nuevo target

	AController* SavedController = GetController(); // Cojo el controller del player que se esta usando
	SavedController->UnPossess(); // Lo dejo de poseer
	SavedController->Possess(); // Controlo el actor que esta en la escena
	*/
	
	UE_LOG(LogTemp, Warning, TEXT("Hola, has pulsado el 1"));
}
void AMyPlayerController::Press2()
{
	UE_LOG(LogTemp, Warning, TEXT("Hola, has pulsado el 2"));
}
void AMyPlayerController::Press3()
{
	UE_LOG(LogTemp, Warning, TEXT("Hola, has pulsado el 3"));
}
void AMyPlayerController::Press4()
{
	UE_LOG(LogTemp, Warning, TEXT("Hola, has pulsado el 4"));
}
void AMyPlayerController::Press5()
{
	UE_LOG(LogTemp, Warning, TEXT("Hola, has pulsado el 5"));
}