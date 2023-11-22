#include "../include/plane_tracking.h"
#include "../include/plane_changes.h"
#include "../include/unity_debug.h"
#include "../include/bounded_plane.h"
#include <string>

void startTracking()
{
    LogMessage("start tracking1");
    testUpdatePlane();
}

void stopTracking()
{
    LogMessage("stop tracking");
}

void destroy()
{
    LogMessage("destroy plane tracking");
}

bool static isFirstGet = true;

void *acquireChanges(
    void *&addedPtr, int &addedLength,
    void *&updatedPtr, int &updatedLength,
    void *&removedPtr, int &removedLength,
    int &elementSize)
{
    PlaneChanges *changes = new PlaneChanges(isFirstGet);
    addedPtr = changes->addedArray;
    updatedPtr = changes->updateArray;
    removedPtr = changes->removedArray;

    addedLength = changes->addedLength;
    updatedLength = changes->updatedLength;
    removedLength = changes->removedLength;
    elementSize = sizeof(BoundedPlane);
    isFirstGet = false;
    return changes;
}

void releaseChanges(void *changes)
{
    PlaneChanges *planeChanges = static_cast<PlaneChanges *>(changes);
    planeChanges->release();
    isFirstGet = true;
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
    ARPlane *plane = PlaneManager::getInstance().getPlaneByTrackableId(trackableId);
    if (plane != nullptr)
    {
        numPoints = plane->boundary.size();
        std::ostringstream oss;
        oss << "acquireBoundary: " << plane << " result: "
            << plane->boundary[0].x << " boundary.address " << &plane->boundary << " trackableId: " << plane->trackableId.subId1 << std::endl;
        LogMessage(oss.str().c_str());
        return plane;
    }
    return nullptr;
}

bool tryCopyBoundary(
    void *plane, void *boundaryOut)
{
    if (plane != nullptr)
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
    return false;
}

/**
 * @brief 测试平面数据
 *
 */
void testUpdatePlane()
{
    LogMessage("add test plane data");
    for (size_t i = 0; i < 5; i++)
    {
        ARPlane arPlane;
        arPlane.trackableId = TrackableId(i, i + 1);
        arPlane.boundary.clear();
        arPlane.boundary.push_back(Vector2(-0.5f + i, 0.5f + i));
        arPlane.boundary.push_back(Vector2(0.5f + i, 0.5f + i));
        arPlane.boundary.push_back(Vector2(-0.5f + i, -0.5f + i));
        arPlane.boundary.push_back(Vector2(0.5f + i, -0.5f + i));
        PlaneManager::getInstance().addOrUpdatePlane(arPlane);
    }
}
