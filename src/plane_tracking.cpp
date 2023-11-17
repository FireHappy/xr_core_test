#include "../include/plane_tracking.h"
#include "../include/unity_math.h"
#include "../include/unity_debug.h"
#include "../include/ar_plane.h"
#include <string>

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

static ARPlane _arPlane;
void *acquireBoundary(
    TrackableId trackableId,
    int &numPoints)
{
    // _arPlane.trackableId = trackableId;
    numPoints = 4;
    for (size_t i = 0; i < numPoints; i++)
    {
        /* code */
        _arPlane.boundary[i] = Vector2(-0.5f, 0.5f);
    }
    _arPlane.trackableId = trackableId;

    std::ostringstream oss;
    oss << "acquireBoundary: " << _arPlane.getNativePtr() << " result: "
        << _arPlane.boundary[0].x << " boundary.address " << _arPlane.boundary << " trackableId: " << _arPlane.trackableId.subId1 << std::endl;
    LogMessage(oss.str().c_str());
    return &_arPlane;
}

bool tryCopyBoundary(
    void *plane, void *boundaryOut)
{
    std::ostringstream oss;
    ARPlane *arPlane = static_cast<ARPlane *>(plane);
    oss << "tryCopyBoundary: " << arPlane << " result: "
        << arPlane->boundary[0].x << " boundary.address " << arPlane->boundary << " trackableId: " << arPlane->trackableId.subId1 << std::endl;
    LogMessage(oss.str().c_str());
    Vector2 *array = static_cast<Vector2 *>(boundaryOut);
    for (size_t i = 0; i < 4; i++)
    {
        array[i] = arPlane->boundary[i];
    }
    std::cout << "hello world " << boundaryOut << "== " << arPlane->boundary << std::endl;
    return true;
}
