#include "../include/plane_changes.h"

PlaneChanges::PlaneChanges(bool firstInit)
{
    if (firstInit)
    {
        addedLength = 5;
        removedLength = 0;
        updatedLength = 0;
        addedArray = new BoundedPlane[5];
        removedArray = new BoundedPlane[0];
        updateArray = new BoundedPlane[0];
        for (size_t i = 0; i < 5; i++)
        {
            BoundedPlane boundedPlane = BoundedPlane(TrackableId(i, i + 1), TrackableId(0, 0), Pose(), Vector2(), Vector2(), PlaneAlignment::HorizontalUp, TrackingState::Tracking, this, PlaneClassification::Floor);
            addedArray[i] = boundedPlane;
        }
    }
    else
    {
        addedLength = 0;
        removedLength = 0;
        updatedLength = 5;
        updateArray = new BoundedPlane[5];
        addedArray = new BoundedPlane[0];
        removedArray = new BoundedPlane[0];
        for (size_t i = 0; i < 5; i++)
        {
            BoundedPlane boundedPlane = BoundedPlane(TrackableId(i, i + 1), TrackableId(0, 0), Pose(), Vector2(), Vector2(), PlaneAlignment::HorizontalUp, TrackingState::Tracking, nullptr, PlaneClassification::Floor);
            addedArray[i] = boundedPlane;
            updateArray[i] = boundedPlane;
        }
    }
}