#include "plane_tracking.h"
#include "../include/unity_math.h"

void startTracking()
{
    std::cout << "startTracking";
}

void stopTracking()
{
    std::cout << "stopTracking";
}

void destroy()
{
    std::cout << "destroy";
}

void *acquireChanges(
    void *addedPtr, int addedLength,
    void *updatedPtr, int updatedLength,
    void *removedPtr, int removedLength,
    int elementSize)
{
    return NULL;
}

void releaseChanges(void *changes)
{
    PlaneChanges *planeChanges = static_cast<PlaneChanges *>(changes);
    planeChanges->release();
}

PlaneDetectionMode getRequestedPlaneDetectionMode()
{
    return PlaneDetectionMode::Horizontal;
}

void setRequestedPlaneDetectionMode(PlaneDetectionMode &mode)
{
    std::cout << "setPlaneDetectionMode:";
}

static ARPlane arPlane;
void *acquireBoundary(
    TrackableId trackableId,
    int numPoints)
{
    arPlane.trackableId = trackableId;
    numPoints = 4;
    arPlane.boundary.push_back(Vector2(-0.5f, 0.5f));
    arPlane.boundary.push_back(Vector2(0.5f, 0.5f));
    arPlane.boundary.push_back(Vector2(0.5f, -0.5f));
    arPlane.boundary.push_back(Vector2(-0.5f, 0.5f));
    return &arPlane;
}

bool tryCopyBoundary(
    void *plane,
    void *boundaryOut)
{
    ARPlane *arplane = static_cast<ARPlane *>(plane);
    if (arplane != nullptr)
    {
        boundaryOut = &(arplane->boundary);
        return true;
    }
    return false;
}