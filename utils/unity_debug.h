
#include <math.h>
#include <string.h>
#include <iostream>

#ifndef _UNITY_DEBUG_
#define _UNITY_DEBUG_

#define _DllExport _declspec(dllexport)

#define UnityLog(acStr)       \
    char acLogStr[512] = {0}; \
    UnityDebug::Log(acLogStr, strlen(acStr));

extern "C"
{
    class UnityDebug
    {
    private:
        /* data */
    public:
        UnityDebug(/* args */);
        ~UnityDebug();

        static void (*Log)(char *message, int iSize);
    };

    // C# call C++
    void _DllExport InitCSharpDelegate(void (*Log)(char *message, int iSize));

    float _DllExport GetDistance(float x1, float y1, float x2, float y2);
}

#endif // !1
