#include "RoadFromArcGISGeoJSON.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "JsonObjectConverter.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Components/SplineMeshComponent.h"

ARoadFromArcGISGeoJSON::ARoadFromArcGISGeoJSON()
{
    PrimaryActorTick.bCanEverTick = false;

    RoadSpline = CreateDefaultSubobject<USplineComponent>(TEXT("RoadSpline"));
    RootComponent = RoadSpline;
}

void ARoadFromArcGISGeoJSON::BeginPlay()
{
    Super::BeginPlay();

    if (!GeoJSONFile.IsEmpty())
    {
        LoadGeoJSON();
    }
}

void ARoadFromArcGISGeoJSON::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ARoadFromArcGISGeoJSON::LoadGeoJSON()
{
    FString FullPath = FPaths::ProjectContentDir() + GeoJSONFile;
    FString FileContent;

    if (!FFileHelper::LoadFileToString(FileContent, *FullPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load GeoJSON: %s"), *FullPath);
        return;
    }

    TSharedPtr<FJsonObject> RootObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContent);

    if (!FJsonSerializer::Deserialize(Reader, RootObject) || !RootObject.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to parse GeoJSON."));
        return;
    }

    const TArray<TSharedPtr<FJsonValue>>* FeaturesArray;
    if (!RootObject->TryGetArrayField(TEXT("features"), FeaturesArray)) return;

    TArray<FVector> RoadPoints;

    for (auto& FeatureValue : *FeaturesArray)
    {
        const TSharedPtr<FJsonObject> FeatureObj = FeatureValue->AsObject();
        if (!FeatureObj.IsValid()) continue;

        const TSharedPtr<FJsonObject> GeometryObj = FeatureObj->GetObjectField(TEXT("geometry"));
        if (!GeometryObj.IsValid()) continue;

        FString Type = GeometryObj->GetStringField(TEXT("type"));
        if (Type != TEXT("LineString")) continue;

        const TArray<TSharedPtr<FJsonValue>>* CoordArray;
        if (!GeometryObj->TryGetArrayField(TEXT("coordinates"), CoordArray)) continue;

        for (auto& CoordVal : *CoordArray)
        {
            const TArray<TSharedPtr<FJsonValue>>* PointArray;
            if (!CoordVal->TryGetArray(PointArray)) continue;

            double Lon = (*PointArray)[0]->AsNumber();
            double Lat = (*PointArray)[1]->AsNumber();
            double Alt = PointArray->Num() > 2 ? (*PointArray)[2]->AsNumber() : 0.0;

            // Unreal uses X=Lon, Y=Lat, Z=Alt as a simple mapping
            RoadPoints.Add(FVector(Lon, Lat, Alt));
        }
    }

    // Clear existing spline points
    RoadSpline->ClearSplinePoints();

    for (int32 i = 0; i < RoadPoints.Num(); i++)
    {
        RoadSpline->AddSplinePoint(RoadPoints[i], ESplineCoordinateSpace::Local, true);
    }

    RoadSpline->UpdateSpline();

    // Create spline meshes
    for (int32 i = 0; i < RoadPoints.Num() - 1; i++)
    {
        CreateSplineMeshSegment(RoadPoints[i], RoadPoints[i + 1]);
    }
}

void ARoadFromArcGISGeoJSON::CreateSplineMeshSegment(const FVector& Start, const FVector& End)
{
    if (!RoadMesh) return;

    USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
    SplineMesh->RegisterComponent();
    SplineMesh->SetStaticMesh(RoadMesh);
    
    if (RoadMaterial)
    {
        SplineMesh->SetMaterial(0, RoadMaterial);
    }

    SplineMesh->SetStartAndEnd(Start, FVector::ZeroVector, End, FVector::ZeroVector);
    SplineMesh->AttachToComponent(RoadSpline, FAttachmentTransformRules::KeepRelativeTransform);
}
