#pragma once
#include <string>

namespace System
{
    void Log(std::string argString);
    void Warning(std::string argString);
    void Error(std::string argString, int argError);
}
