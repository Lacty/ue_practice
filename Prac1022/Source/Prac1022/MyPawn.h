// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class PRAC1022_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	UPROPERTY(EditAnywhere)
  USceneComponent* Player;
  
  bool IsJump;
  
  FVector JumpVelocity;
  
  UPROPERTY(EditAnywhere)
  FVector JumpPower;
  
  void Move_XAxis(float AxisValue);
  void Move_YAxis(float AxisValue);
  void StartJump();
  
  FVector CurrentVelocity;
};
