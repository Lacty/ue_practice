// Fill out your copyright notice in the Description page of Project Settings.

#include "Prac1022.h"
#include "MyPawn.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  // こいつはPlayer0だぜい
  AutoPossessPlayer = EAutoReceiveInput::Player0;
  
  RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
  
  Player = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player"));
  
  Player->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
  
  if (!CurrentVelocity.IsZero())
  {
    FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
    SetActorLocation(NewLocation);
  }
  
  if (IsJump)
  {
    JumpVelocity.Z -= DeltaTime * 80.0f;
    FVector NewLocation = GetActorLocation() + JumpVelocity;
    
    const float Floor = 10.0f;
    
    if (NewLocation.Z < Floor)
    {
      NewLocation.Z = Floor;
      IsJump = false;
    }
    
    SetActorLocation(NewLocation);
  }
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

  InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
  InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);
  
  InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPawn::StartJump);
}

void AMyPawn::Move_XAxis(float AxisValue)
{
  CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::Move_YAxis(float AxisValue)
{
  CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::StartJump()
{
  if (IsJump) { return; }
  JumpVelocity = JumpPower;
  IsJump= true;
}