#include <iostream>
#include <regex>
#include <sstream>
#include <iomanip>
#include "bounded_plane.h"
#include "rokid_unity_math.h";

#ifndef __PLANE_CHANGES__H__
#define __PLANE_CHANGES__H__

class PlaneChanges
{
public:
    BoundedPlane *GetAddBoundedPlane()
    {
        return addArray;
    }

    BoundedPlane *GetRemoveBoundedPlane()
    {
        return removeArray;
    }

    BoundedPlane *GetUpdateBoundedPlane()
    {
        return updateArray;
    }

    void Initialize()
    {
        addArray = new BoundedPlane[10];
        removeArray = new BoundedPlane[10];
        for (size_t i = 0; i < 10; i++)
        {
            BoundedPlane plane = BoundedPlane(TrackableId(1, 2), TrackableId(1, 2), Pose(), Vector2(), Vector2(), PlaneAlignment::HorizontalUp, TrackingState::Tracking, &plane, PlaneClassification::Floor);
            this->addArray[i] = plane;
            this->updateArray[i] = plane;
        }
    }

    void Release()
    {
        delete[] addArray;
        delete[] removeArray;
        delete[] updateArray;
    }

private:
    BoundedPlane *addArray;
    BoundedPlane *removeArray;
    BoundedPlane *updateArray;
};

#endif //!__PLANE_CHANGES__H__