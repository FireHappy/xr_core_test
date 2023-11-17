

#ifndef __BOUNDED_PLANE__H__
#define __BOUNDED_PLANE__H__

#include "plane_tracking_enum.h"
#include "unity_math.h"
#include "trackable_id.h"
struct BoundedPlane
{
  static const BoundedPlane Default;

  TrackableId trackableId;
  TrackableId subsumedById;
  Pose pose;
  Vector2 center;
  Vector2 size;
  PlaneAlignment alignment;
  TrackingState trackingState;
  void *nativePtr; // Assuming IntPtr is a pointer type
  PlaneClassification classification;

  BoundedPlane()
      : trackableId(0),
        subsumedById(0),
        pose(),
        center(),
        size(),
        alignment(PlaneAlignment::None),
        trackingState(TrackingState::None),
        nativePtr(nullptr),
        classification(PlaneClassification::None) {}

  BoundedPlane(
      const TrackableId &trackableId,
      const TrackableId &subsumedById,
      const Pose &pose,
      const Vector2 &center,
      const Vector2 &size,
      PlaneAlignment alignment,
      TrackingState trackingState,
      void *nativePtr,
      PlaneClassification classification)
      : trackableId(trackableId),
        subsumedById(subsumedById),
        pose(pose),
        center(center),
        size(size),
        alignment(alignment),
        trackingState(trackingState),
        nativePtr(nativePtr),
        classification(classification) {}
};

#endif //!__BOUNDED_PLANE__H__
