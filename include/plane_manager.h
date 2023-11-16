#ifndef __PLANE_MANAGER__H__
#define __PLANE_MANAGER__H__
#include <list>
#include "arplane.h"

class PlaneManager
{
public:
    static PlaneManager &getInstance()
    {
        static PlaneManager instance;
        return instance;
    }

    ARPlane *getPlaneByTrackableId(TrackableId targetId);

    void addOrUpdatePlane(ARPlane &plane);

    void *getNativePtr()
    {
        return &getInstance();
    }

private:
    PlaneManager() {}
    ~PlaneManager() {}

    std::list<ARPlane> planeList;
};

#endif //!__PLANE_MANAGER__H__