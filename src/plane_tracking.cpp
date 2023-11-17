#include "../include/plane_tracking.h"
#include "../include/plane_changes.h"
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
    return nullptr;
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
    LogMessage("setPlaneDetectionMode");
}

void *acquireBoundary(
    TrackableId trackableId,
    int &numPoints)
{
    numPoints = 4;
    static ARPlane arPlane;
    arPlane.trackableId = trackableId;
    arPlane.boundary.clear();
    arPlane.boundary.push_back(Vector2(-0.5f, 0.5f));
    arPlane.boundary.push_back(Vector2(0.5f, 0.5f));
    arPlane.boundary.push_back(Vector2(-0.5f, -0.5f));
    arPlane.boundary.push_back(Vector2(0.5f, -0.5f));
    std::ostringstream oss;
    oss << "acquireBoundary: " << arPlane.getNativePtr() << " result: "
        << arPlane.boundary[0].x << " boundary.address " << &arPlane.boundary << " trackableId: " << arPlane.trackableId.subId1 << std::endl;
    LogMessage(oss.str().c_str());
    return arPlane.getNativePtr();
}

bool tryCopyBoundary(
    void *plane, void *boundaryOut)
{
    std::ostringstream oss;
    ARPlane *arPlane = static_cast<ARPlane *>(plane);
    oss << "tryCopyBoundary: " << arPlane << " result: "
        << arPlane->boundary[0].x << " boundary.address " << &(arPlane->boundary) << " trackableId: " << arPlane->trackableId.subId1 << std::endl;
    LogMessage(oss.str().c_str());
    Vector2 *array = static_cast<Vector2 *>(boundaryOut);
    for (size_t i = 0; i < arPlane->boundary.size(); i++)
    {
        array[i] = arPlane->boundary[i];
    }
    return true;
}
