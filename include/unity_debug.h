#include <iostream>
#include <string>

typedef void (*LogCallback)(const char *);

// Callback function pointer
static LogCallback callback = nullptr;

extern "C"
{
    // Function to set the ccallback from C#
    void SetLogCallback(LogCallback callback);

    // Function to log a message from C++
    void LogMessage(const char *message);
}
