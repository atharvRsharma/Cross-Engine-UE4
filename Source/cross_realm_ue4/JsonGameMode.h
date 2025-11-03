#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JsonGameMode.generated.h"

class AGlowingOrb;

USTRUCT(BlueprintType)
struct FOrbStateData
{
	GENERATED_BODY()
	UPROPERTY() FVector position;
	UPROPERTY() FVector velocity;
	UPROPERTY() float energy;
	UPROPERTY() FString id;
	UPROPERTY() FString state;
	UPROPERTY() bool isGravityOn;
};

UCLASS()
class CROSS_REALM_UE4_API AJsonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void SpawnOrUpdateOrb();

protected:
	virtual void BeginPlay() override;

	bool LoadOrbState(FOrbStateData& OutData);

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AGlowingOrb> OrbClassToSpawn;

private:
	UPROPERTY()
	AGlowingOrb* SpawnedOrb;
};