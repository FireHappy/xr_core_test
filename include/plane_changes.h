

#ifndef __PLANE_CHANGES__H__
#define __PLANE_CHANGES__H__

#include <iostream>
#include <regex>
#include <sstream>
#include <iomanip>
#include "bounded_plane.h"
#include "unity_math.h"

class PlaneChanges
{
public:
    BoundedPlane *getAddBoundedPlane();

    BoundedPlane *getRemoveBoundedPlane();

    BoundedPlane *getUpdateBoundedPlane();

    void initialize();

    void release();

private:
    BoundedPlane *addArray;
    BoundedPlane *removeArray;
    BoundedPlane *updateArray;
};

#endif //!__PLANE_CHANGES__H__