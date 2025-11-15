#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "RoadFromArcGISGeoJSON.generated.h"

UCLASS()
class COLEA4V8_API ARoadFromArcGISGeoJSON : public AActor
{
    GENERATED_BODY()

public:
    ARoadFromArcGISGeoJSON();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // --- Spline to hold road points ---
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Road")
    USplineComponent* RoadSpline;

    // --- Material property exposed to the Editor ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road")
    UMaterialInterface* RoadMaterial;

    // --- Function to add points to the spline ---
    void AddRoadPoint(const FVector& Point);

private:
    // Keep track of created spline mesh components
    UPROPERTY()
    TArray<USplineMeshComponent*> SplineMeshes;
};
