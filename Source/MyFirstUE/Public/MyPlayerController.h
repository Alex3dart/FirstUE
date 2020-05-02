// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYFIRSTUE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnyWhere)
	TArray<class ACarPawn*> Pawns;

public :
	AMyPlayerController();

	virtual void BeginPlay() override;
private:

	AController* SavedController;

	void Press1();
	void Press2();
	void Press3();
	void Press4();
	void Press5();
};
