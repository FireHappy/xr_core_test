#include "rokid_unity_math.h"
#include "trackableId.h"
#include <vector>

#ifndef __ARPLANE__H__
#define __ARPLANE__H__

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