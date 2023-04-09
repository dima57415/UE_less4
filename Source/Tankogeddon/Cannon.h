// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStruct.h"
#include "Projectile.h"
#include "Cannon.generated.h"


UCLASS()
class TANKOGEDDON_API ACannon : public AActor
{
	GENERATED_BODY()
	
public:	
	ACannon();

	void Fire();
	void FireSpecial();
	bool IsReadyToFire();
	void Reload();
	void DelayFire_();
	void AddAmmo(uint32_t _Ammo);

protected:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* CannonMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* ProjectileSpawnComponent;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	//class UArrowComponent* ProjectileSpawnPoint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	ECannonType CannonType = ECannonType::FireProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	ECannonSpecialType CannonSpecialType = ECannonSpecialType::SpecialFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	TSubclassOf<class AProjectile> ProjectileClass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	float FireRate = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	float FireDelay = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	float FireRange = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire params")
	float FireDanage = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int Ammo = 10;

	bool bReadyToFire = true;
	bool bDelayToFire = true;
	FTimerHandle ReloadTimer;
	FTimerHandle DelayTimer;


public:	
	virtual void Tick(float DeltaTime) override;

};
