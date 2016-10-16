// Fill out your copyright notice in the Description page of Project Settings.

#include "Prac01.h"
#include "PlayerPawn.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  // 入力を受け付けるように設定する
  // このPawnは1pとして認識される
  AutoPossessPlayer = EAutoReceiveInput::Player0;
  
  // このPawnを実体化させる
  RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
  
  // 可視オブジェクトを作成
  VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
  
  // 可視オブジェクトをRootに親子ずけ
  VisibleComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

  if (!CurrentVelocity.IsZero())
  {
    FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
    SetActorLocation(NewLocation);
  }
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
  
  // InputFunctionを紐付けする
  InputComponent->BindAxis("MoveX", this, &APlayerPawn::Move_XAxis);
  InputComponent->BindAxis("MoveY", this, &APlayerPawn::Move_YAxis);
}

void APlayerPawn::Move_XAxis(float AxisValue)
{
  CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void APlayerPawn::Move_YAxis(float AxisValue)
{
  CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

