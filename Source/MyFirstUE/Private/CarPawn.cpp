// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
ACarPawn::ACarPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Hola
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	StaticMeshComp->SetupAttachment(RootComponent);
	SpringArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SpringArmComp);

	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SocketOffset = FVector(0, 0, 300);
}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Hello, Begin Play Here"));

}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent && "Can't found PlayerInputComponent"); 

	PlayerInputComponent->BindAction("MyInput", EInputEvent::IE_Pressed, this, &ACarPawn::OnSpaceInput); // 'this' is UserClass
	PlayerInputComponent->BindAxis("MoveVertical", this, &ACarPawn::OnMoveVertical);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &ACarPawn::OnMoveHorizontal);
	PlayerInputComponent->BindAxis("MouseVertical", this, &ACarPawn::OnMouseVertical);
	PlayerInputComponent->BindAxis("MouseHorizontal", this, &ACarPawn::OnMouseHorizontal);
	PlayerInputComponent->BindAxis("MouseWheel", this, &ACarPawn::OnMouseWheel);
}
void ACarPawn::OnSpaceInput()
{
	UE_LOG(LogTemp, Warning, TEXT("OnSpaceInput Here"));

}

void ACarPawn::OnMoveVertical(float axisV)
{
	FVector vectorV = GetActorForwardVector();
	AddMovementInput(vectorV, axisV, false);
}
void ACarPawn::OnMoveHorizontal(float axisH)
{
	FVector vectorH = GetActorRightVector();
	AddMovementInput(vectorH, axisH, false);
}
void ACarPawn::OnMouseVertical(float axisMouseV) 
{
	AddControllerPitchInput(axisMouseV);
	
}

void ACarPawn::OnMouseHorizontal(float axisMouseH) 
{
	 AddControllerYawInput(axisMouseH);
}

void ACarPawn::OnMouseWheel(float axisWheel)
{
	
	float vector = SpringArmComp->TargetArmLength + (axisWheel * 5);
	SpringArmComp->TargetArmLength = vector;
	
}
