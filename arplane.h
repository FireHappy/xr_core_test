#include "rokid_unity_math.h"
#include "trackableId.h"

#ifndef __ARPLANE__H__
#define __ARPLANE__H__

struct ARPlane
{
    TrackableId trackableId;
    Vector2 *boundary;
};

#endif //!__ARPLANE__H__