// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStruct.generated.h"



UENUM(BlueprintType)
enum class ECannonType : uint8
{
	FireTrace = 0 UMETA(DisplayName = "Use trace"),
	FireProjectile = 1 UMETA(DisplayName = "Use projectile")
};

UENUM(BlueprintType)
enum class ECannonSpecialType : uint8
{
	SpecialFire = 0 UMETA(DisplayName = "Use SpecialFire")
};

UCLASS()
class TANKOGEDDON_API UGameStruct : public UObject
{
	GENERATED_BODY()
};
