#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Engine/StaticMesh.h"
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

    /** The spline component that defines the road path */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Road")
    USplineComponent* RoadSpline;

    /** The material to apply to the spline mesh */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Road Settings")
    UMaterialInterface* RoadMaterial;

    /** The mesh to use for the spline segments */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Road Settings")
    UStaticMesh* RoadMesh;

    /** Load GeoJSON file path (relative to Content folder) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Road Settings")
    FString GeoJSONFile;

    /** Function to load the GeoJSON and create the spline */
    UFUNCTION(CallInEditor, Category="Road")
    void LoadGeoJSON();

private:
    void CreateSplineMeshSegment(const FVector& Start, const FVector& End);
};
