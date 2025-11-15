#include "RoadFromArcGISGeoJSON.h"
#include "Components/SplineMeshComponent.h"

ARoadFromArcGISGeoJSON::ARoadFromArcGISGeoJSON()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create spline component
    RoadSpline = CreateDefaultSubobject<USplineComponent>(TEXT("RoadSpline"));
    RootComponent = RoadSpline;
}

void ARoadFromArcGISGeoJSON::BeginPlay()
{
    Super::BeginPlay();
}

void ARoadFromArcGISGeoJSON::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Add a point to the spline and automatically create a mesh between points
void ARoadFromArcGISGeoJSON::AddRoadPoint(const FVector& Point)
{
    int32 NumPoints = RoadSpline->GetNumberOfSplinePoints();

    RoadSpline->AddSplinePoint(Point, ESplineCoordinateSpace::Local);

    if (NumPoints > 0) // Create spline mesh between last point and new point
    {
        FVector StartPos, StartTangent, EndPos, EndTangent;
        RoadSpline->GetLocationAndTangentAtSplinePoint(NumPoints - 1, StartPos, StartTangent, ESplineCoordinateSpace::Local);
        RoadSpline->GetLocationAndTangentAtSplinePoint(NumPoints, EndPos, EndTangent, ESplineCoordinateSpace::Local);

        USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
        SplineMesh->SetMobility(EComponentMobility::Movable);
        SplineMesh->AttachToComponent(RoadSpline, FAttachmentTransformRules::KeepRelativeTransform);

        // Set mesh to a basic cube or placeholder (replace with your road mesh)
        static ConstructorHelpers::FObjectFinder<UStaticMesh> RoadMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
        if (RoadMesh.Succeeded())
        {
            SplineMesh->SetStaticMesh(RoadMesh.Object);
        }

        // Assign the road material if specified
        if (RoadMaterial)
        {
            SplineMesh->SetMaterial(0, RoadMaterial);
        }

        SplineMesh->SetStartAndEnd(StartPos, StartTangent, EndPos, EndTangent);
        SplineMesh->RegisterComponent();

        SplineMeshes.Add(SplineMesh);
    }
}
