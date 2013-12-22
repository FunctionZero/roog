#include "system_main.hpp"
#include "system_loop.hpp"
#include "system_global.hpp"
#include "system_random.hpp"
#include "libtcod_main.hpp"
#include "interface_main.hpp"
#include "interface_mainmenu.hpp"

int main()
{
    System::Initialize();

    while(!Global::endProgram && !TCODConsole::isWindowClosed())
    {
        System::Loop();
    }

    return EXIT_SUCCESS;
}

namespace System
{
    void Initialize()
    {
        LibTCOD::Initialize();
        Interface::Initialize();

        MainMenu::Open();
    }
}
