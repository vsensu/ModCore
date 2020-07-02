// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModActor.generated.h"

UCLASS()
class MODCOREPLUGIN_API AModActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mod Actor")
	FString Author;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mod Actor")
	FString ModName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mod Actor")
	FString Desc;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mod Actor")
	FString Version;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "SetupInitOrder"), Category = "Mod Actor")
	void ReceiveSetupInitOrder();

	UFUNCTION(BlueprintCallable, Category = "Mod Actor")
	virtual void SetupInitOrder();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "InitMod"), Category = "Mod Actor")
	void ReceiveInitMod();

	UFUNCTION(BlueprintCallable, Category = "Mod Actor")
	virtual void InitMod();

	UFUNCTION(BlueprintCallable, Category = "Mod Actor")
	FString GetModKey() const;
};
