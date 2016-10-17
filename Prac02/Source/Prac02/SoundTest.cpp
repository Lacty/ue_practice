// Fill out your copyright notice in the Description page of Project Settings.

#include "Prac02.h"
#include "SoundTest.h"


// Sets default values
ASoundTest::ASoundTest()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  
  AutoPossessPlayer = EAutoReceiveInput::Player0;
  
  RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
  
  MySound = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}

// Called when the game starts or when spawned
void ASoundTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoundTest::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ASoundTest::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

  InputComponent->BindAction("Play", IE_Pressed, this, &ASoundTest::PlaySound);
}

void ASoundTest::PlaySound()
{
  MySound->Play();
}