

#ifndef __PLANE_CHANGES__H__
#define __PLANE_CHANGES__H__

#include "bounded_plane.h"
#include "unity_math.h"

class PlaneChanges
{
public:
    static PlaneChanges &getInstance()
    {
        static PlaneChanges instance;
        return instance;
    }

    BoundedPlane *getAddBoundedPlane();

    BoundedPlane *getRemoveBoundedPlane();

    BoundedPlane *getUpdateBoundedPlane();

    void initialize();

    void release();

    void *getNativePtr()
    {
        return &getInstance();
    }

private:
    PlaneChanges() {}
    ~PlaneChanges() {}

    BoundedPlane *addArray;
    BoundedPlane *removeArray;
    BoundedPlane *updateArray;
};

#endif //!__PLANE_CHANGES__H__