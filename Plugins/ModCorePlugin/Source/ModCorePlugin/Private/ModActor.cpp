// Fill out your copyright notice in the Description page of Project Settings.


#include "ModActor.h"
#include "..\Public\ModActor.h"

// Sets default values
AModActor::AModActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AModActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AModActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AModActor::SetupInitOrder()
{
	ReceiveSetupInitOrder();
}

void AModActor::InitMod()
{
	ReceiveInitMod();
}

FString AModActor::GetModKey() const
{
	return FString::Printf(TEXT("%s:%s"), *Author, *ModName);
}

void AModActor::InitBefore(FString modKeyBefore, FString minimalVersion)
{
	FModDependencyDesc desc;
	desc.MinimalVersion = minimalVersion;
	InitBeforeOthers.Add(modKeyBefore, desc);
}

void AModActor::InitAfter(FString modKeyAfter, FString minimalVersion)
{
	FModDependencyDesc desc;
	desc.MinimalVersion = minimalVersion;
	InitAfterOthers.Add(modKeyAfter, desc);
}
