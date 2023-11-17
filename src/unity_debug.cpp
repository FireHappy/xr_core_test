#include "../include/unity_debug.h"

void SetLogCallback(LogCallback cb)
{
    callback = cb;
}

void LogMessage(const char *message)
{
    if (callback)
        callback(message);
}
