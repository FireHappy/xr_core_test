#include "../include/unity_debug.h"
#include <iostream>

void SetLogCallback(LogCallback cb)
{
    callback = cb;
}

void LogMessage(const char *message)
{
    if (callback)
    {
        callback(message);
    }
    else
    {
        std::cout << message << std::endl;
    }
}
