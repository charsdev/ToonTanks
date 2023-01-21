#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;
class UCameraShake;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	AProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& hit);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh{ nullptr };

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent{ nullptr };

	UPROPERTY(EditAnywhere)
	float Damage{ 50.f };

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* HitParticles{ nullptr };

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	class UParticleSystemComponent* TrailParticles{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};