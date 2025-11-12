// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "http.h"
#include "FeatureLayerQuery.generated.h"

USTRUCT(BlueprintType)
struct FGeometries
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<float> geometry;
	
};

	USTRUCT (BlueprintType)
	struct FProperties
{
	GENERATED_BODY()

	UPROPERTY (BlueprintReadonly, VisibleAnywhere, Category="Properties")
	int32 altitude;
	UPROPERTY (BlueprintReadonly, VisibleAnywhere, Category="Properties")
	int32 length;
	UPROPERTY(BLueprintReadonly, VisibleAnywhere,Category= "Properties")
	FString Location;
	UPROPERTY (BLueprintReadonly, VisibleAnywhere, Category="Properties")
	FString name;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Geometry")
	TArray<FGeometries> Geometries;
};

UCLASS()
class COLEA4V8_API AFeatureLayerQuery : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFeatureLayerQuery();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccessfullyConnected);
	virtual void ProcessRequest();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FProperties> Features;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString weblink = "http://www.w3.org/2000/web/";
};

