#include "plane_tracking.h"

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

void *acquireBoundary(
    TrackableId trackableId,
    int numPoints)
{
    // ARPlane *plane = PlaneManager::getInstance().getPlaneByTrackableId(trackableId);
    // if (plane != nullptr)
    // {
    //     numPoints = plane->boundary.size();
    //     return plane->getNativePtr();
    // }
    return nullptr;
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