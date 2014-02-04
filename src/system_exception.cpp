#include <fstream>
#include "system_exception.hpp"

namespace System
{
    void WriteToFile(std::string argString, std::string filename)
    {
        std::ofstream strm(filename.c_str(), std::ios::app);

        strm << argString << '\n';
        strm.flush();
        strm.close();
    }

    void Log(std::string argString)
    {
        WriteToFile(argString, "roog.log");
    }

    void Warning(std::string argString)
    {
        argString.insert(0, "Warning: ");
        WriteToFile(argString, "roog.log");
    }

    void Error(std::string argString)
    {
        argString.insert(0, "Error: ");
        WriteToFile(argString, "roog.log");
        exit(-1);
    }
}
