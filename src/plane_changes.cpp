#include "../include/plane_changes.h"

BoundedPlane *PlaneChanges::getAddBoundedPlane()
{
    return addArray;
}

BoundedPlane *PlaneChanges::getRemoveBoundedPlane()
{
    return removeArray;
}

BoundedPlane *PlaneChanges::getUpdateBoundedPlane()
{
    return updateArray;
}

void PlaneChanges::initialize() {}

void PlaneChanges::release() {}
