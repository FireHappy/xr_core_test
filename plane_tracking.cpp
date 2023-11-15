
#include "plane_tracking.h"
#include <cstddef>
#include <iostream>

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
    std::cout << "releaseChanges";
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
    return NULL;
}

bool tryCopyBoundary(
    void *plane,
    void *boundaryOut)
{
    return false;
}