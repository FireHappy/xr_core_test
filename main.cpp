#include <iostream>
#include "include/unity_debug.h"
#include "include/plane_tracking.h"
#include "include/trackable_id.h"
#include "include/unity_math.h"
int main(int argc, const char **argv)
{
    int numPoint;
    void *plane = acquireBoundary(TrackableId(2, 1), numPoint);
    const int size = numPoint;
    Vector2 boundary[size];
    tryCopyBoundary(plane, boundary);
    for (size_t i = 0; i < numPoint; i++)
    {
        /* code */
        std::cout << "boundaryData: "
                  << " x: " << boundary[i].x << " y: " << boundary[i].y << std::endl;
    }
    std::cout
        << "helo world " << &boundary << std::endl;
    std::cout << "hello world " << numPoint << std::endl;
    return 0;
}