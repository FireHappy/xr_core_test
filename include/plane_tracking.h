#ifndef __PLANE_TRACKING__H__
#define __PLANE_TRACKING__H__

#include <iostream>
#include <regex>
#include <sstream>
#include <iomanip>
#include <cstddef>
#include <iostream>
#include "trackable_id.h"
#include "plane_manager.h"

extern "C"
{
    /**
     * @brief start plane tracking
     */
    void startTracking();
    /**
     * @brief stop plane tracking
     */
    void stopTracking();
    /**
     * @brief destroy plane tracking
     */
    void destroy();
    /// @brief acquire changes
    /// @param addedPtr
    /// @param addedLength
    /// @param updatedPtr
    /// @param updatedLength
    /// @param removedPtr
    /// @param removedLength
    /// @param elementSize
    /// @return
    void *acquireChanges(
        void *addedPtr, int addedLength,
        void *updatedPtr, int updatedLength,
        void *removedPtr, int removedLength,
        int elementSize);
    /**
     * @brief release changes
     * @param changes
     */
    void releaseChanges(void *changes);
    /**
     * @brief Get the Requested Plane Detection Mode object
     * @return PlaneDetectionMode
     */

    PlaneDetectionMode getRequestedPlaneDetectionMode();
    /**
     * @brief Set the Requested Plane Detection Mode object
     * @param mode
     */

    void setRequestedPlaneDetectionMode(PlaneDetectionMode &mode);

    /// @brief acquire boundary
    /// @param trackableId
    /// @param numPoints
    /// @return
    void *acquireBoundary(
        TrackableId trackableId,
        int &numPoints);

    /// @brief try copy boundary
    /// @param plane
    /// @param boundaryOut
    /// @return
    bool tryCopyBoundary(
        void *plane, void *boundaryOut);
}

#endif //!__PLANE_TRACKING__H__
