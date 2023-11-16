#ifndef __ROKID_XR_CORE_ENUM__H__
#define __ROKID_XR_CORE_ENUM__H__
// <summary>
/// Represents the alignment of a plane (for example, whether it is horizontal
/// or vertical).
/// </summary>
/// <seealso cref="BoundedPlane.alignment"/>
enum class PlaneAlignment {
  /// <summary>
  /// No alignment.
  /// </summary>
  None = 0,

  /// <summary>
  /// The plane is horizontal with an upward facing normal (for example, a
  /// floor).
  /// </summary>
  HorizontalUp = 100,

  /// <summary>
  /// The plane is horizontal with a downward facing normal (for example, a
  /// ceiling).
  /// </summary>
  HorizontalDown = 101,

  /// <summary>
  /// The plane is vertical (for example, a wall).
  /// </summary>
  Vertical = 200,

  /// <summary>
  /// The plane is not aligned with any axis.
  /// </summary>
  NotAxisAligned = 300
};

// Enum for TrackingState
enum class TrackingState {
  None,
  Limited,
  Tracking,
};

enum class PlaneDetectionMode {
  /// <summary>
  /// Plane detection is disabled.
  /// </summary>s
  None = 0,

  /// <summary>
  /// Plane detection will only detect horizontal planes.
  /// </summary>
  Horizontal = 1 << 0,

  /// <summary>
  /// Plane detection will only detect vertical planes.
  /// </summary>
  Vertical = 1 << 1
};

// Enum for PlaneClassification
enum class PlaneClassification {
  None,
  Wall,
  Floor,
  Ceiling,
  Table,
  Seat,
  Door,
  Window,
  Doorway,
  WindowLike,
};
#endif //!__ROKID_XR_CORE_ENUM__H__
