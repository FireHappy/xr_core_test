#include "../include/plane_manager.h"

ARPlane *PlaneManager::getPlaneByTrackableId(TrackableId targetId)
{
    for (ARPlane &plane : planeList)
    {
        if (plane.trackableId == targetId)
        {
            return &plane;
        }
    }
    return nullptr;
}

void PlaneManager::addOrUpdatePlane(ARPlane &plane)
{
    ARPlane *planePtr = getPlaneByTrackableId(plane.trackableId);
    if (planePtr != nullptr)
    {
        planePtr->boundary = plane.boundary;
    }
    else
    {
        planeList.push_front(plane);
    }
}
