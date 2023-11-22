#ifndef __TRACKABLEID__H__
#define __TRACKABLEID__H__

#include <iostream>
#include <regex>
#include <sstream>
#include <iomanip>
#include "plane_tracking_enum.h"
struct TrackableId
{
    uint64_t subId1;
    uint64_t subId2;

    static const TrackableId invalidId;

    TrackableId(uint64_t subId1, uint64_t subId2)
        : subId1(subId1), subId2(subId2) {}

    std::string ToString() const
    {
        std::stringstream ss;
        ss << std::hex << std::setfill('0') << std::setw(16) << subId1 << "-"
           << std::hex << std::setfill('0') << std::setw(16) << subId2;
        return ss.str();
    }

    bool operator==(const TrackableId &other) const
    {
        return (subId1 == other.subId1) && (subId2 == other.subId2);
    }

    bool operator!=(const TrackableId &other) const
    {
        return !(*this == other);
    }
};

#endif //!__TRACKABLEID__H__
