

#ifndef __ARPLANE__H__
#define __ARPLANE__H__

#include "unity_math.h"
#include "trackable_id.h"
#include <vector>

struct ARPlane
{
    TrackableId trackableId;
    std::vector<Vector2> boundary;
    ARPlane() : trackableId(0, 0), boundary() {}
    ARPlane *getNativePtr()
    {
        return this;
    }
};

#endif //!__ARPLANE__H__