#include "../include/plane_tracking.h"
#include "../include/unity_math.h"
#include "../include/unity_debug.h"

void startTracking()
{
    LogMessage("start tracking");
}

void stopTracking()
{
    LogMessage("stop tracking");
}

void destroy()
{
    LogMessage("destroy plane tracking");
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
}

PlaneDetectionMode getRequestedPlaneDetectionMode()
{
    return PlaneDetectionMode::Horizontal;
}

void setRequestedPlaneDetectionMode(PlaneDetectionMode &mode)
{
    LogMessage("setPlaneDetectionMode");
}

static ARPlane arPlane;
void *acquireBoundary(
    TrackableId trackableId,
    int &numPoints)
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