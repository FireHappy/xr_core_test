#include "rokid_xr_core_enum.h"
#include "rokid_unity_math.h"
#include "trackableId.h"

#ifndef __BOUNDED_PLANE__H__
#define __BOUNDED_PLANE__H__

// Struct for BoundedPlane
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

const BoundedPlane BoundedPlane::Default;

#endif //!__BOUNDED_PLANE__H__
