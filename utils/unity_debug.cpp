#include "unity_debug.h"

void (*UnityDebug::Log)(char *message, int iSize);

float GetDistance(float x1, float y1, float x2, float y2)
{
    UnityLog("GetDistance has been called");
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void InitCSharpDelegate(void (*Log)(char *message, int iSize))
{
    UnityDebug::Log = Log;
    UnityLog("Cpp Message:Log has initialized");
}