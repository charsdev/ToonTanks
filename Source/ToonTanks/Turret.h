// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Turret.generated.h"

UCLASS()
class TOONTANKS_API ATurret : public ABasePawn
{
	GENERATED_BODY()
private: 
	void CheckFireRateCondition();
	bool InFireRange();

protected: 
	virtual void BeginPlay() override;
public: 
	ATurret();
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

private:
	class ATank* Tank{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange{ 300.f };

	FTimerHandle FireRateTimerHandle;

	float FireRate{ 2.f };
};
