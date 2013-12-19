#include "system_main.hpp"
#include "system_loop.hpp"
#include "system_global.hpp"
#include "libtcod_main.hpp"

int main()
{
    System::Initialize();

    while(!Global::endProgram && !TCODConsole::isWindowClosed())
    {
        System::Loop();
    }

    return 0;
}

namespace System
{
    void Initialize()
    {
        LibTCOD::Initialize();

        //MainMenu::Open();
    }
}
