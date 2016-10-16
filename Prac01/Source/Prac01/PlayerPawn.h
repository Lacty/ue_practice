// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class PRAC01_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

  // 可視オブジェクト
  // つまりCube(Player)
	UPROPERTY(EditAnywhere)
  USceneComponent* VisibleComponent;
  
  // Input Functions
  void Move_XAxis(float AxisValue);
  void Move_YAxis(float AxisValue);
  
  // Input Variables
  FVector CurrentVelocity;
};
