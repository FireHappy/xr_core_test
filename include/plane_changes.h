

#ifndef __PLANE_CHANGES__H__
#define __PLANE_CHANGES__H__

#include "bounded_plane.h"
#include "plane_tracking_enum.h"
#include "trackable_id.h"
#include "unity_math.h"

class PlaneChanges
{
public:
    PlaneChanges(bool firstInit);

    void *getNativePtr()
    {
        return this;
    }

    void release()
    {
        delete[] addedArray;
        delete[] removedArray;
        delete[] updateArray;
    }

    BoundedPlane *addedArray;
    BoundedPlane *removedArray;
    BoundedPlane *updateArray;

    int addedLength;
    int removedLength;
    int updatedLength;
};

#endif //!__PLANE_CHANGES__H__