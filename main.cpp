#include <iostream>
#include "include/bounded_plane.h"
#include "include/ar_plane.h"
#include "include/unity_debug.h"
#include "include/plane_tracking.h"
#include "include/trackable_id.h"
#include "include/unity_math.h"
#include "include/plane_manager.h"

void testAddOrUpdate()
{
    ARPlane plane01, plane02;
    plane01.trackableId = TrackableId(0, 1);
    plane01.boundary.push_back(Vector2(0, 0));
    plane02.trackableId = TrackableId(0, 1);
    plane02.boundary.push_back(Vector2(1, 1));
    PlaneManager::getInstance()
        .addOrUpdatePlane(plane01);
    PlaneManager::getInstance()
        .addOrUpdatePlane(plane02);
    ARPlane *plane = PlaneManager::getInstance().getPlaneByTrackableId(TrackableId(0, 1));
    std::cout << "plane: " << plane->boundary[0].x << " " << plane->boundary[0].y << std::endl;
}

int main(int argc, const char **argv)
{
    // startTracking();
    // int numPoint;
    // TrackableId trackableId = TrackableId(2, 2);
    // void *plane = acquireBoundary(trackableId, numPoint);
    // const int m_Size = numPoint;
    // Vector2 boundary[m_Size];
    // if (tryCopyBoundary(plane, boundary))
    // {
    //     for (size_t i = 0; i < numPoint; i++)
    //     {
    //         std::cout << "boundaryData: "
    //                   << " x: " << boundary[i].x << " y: " << boundary[i].y << std::endl;
    //     }
    //     std::cout
    //         << "boundary.address " << &boundary << std::endl;
    // }
    // else
    // {
    //     std::cout << "can not find target plane " << trackableId.ToString() << std::endl;
    // }
    // testAddOrUpdate();

    void *addPtr;
    void *removePtr;
    void *updatePtr;
    std::cout << addPtr << std::endl;
    int addLength, removeLength, updateLength, elementSize;
    acquireChanges(addPtr, addLength, updatePtr, updateLength, removePtr, removeLength, elementSize);
    std::cout << addPtr << std::endl;

    BoundedPlane *addPlane = static_cast<BoundedPlane *>(addPtr);
    for (size_t i = 0; i < addLength; i++)
    {
        std::cout << addPlane[i].trackableId.ToString() << std::endl;
    }

    return 0;
}
