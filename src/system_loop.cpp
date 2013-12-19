#include "system_loop.hpp"
#include "system_global.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_mainmenu.hpp"

namespace System
{
    void Loop()
    {
        LibTCOD::Clear();
        LibTCOD::CheckForEvent();

        switch(Global::gameState)
        {
        case STATE_MAINMENU:
            MainMenu::Loop();
            break;
        }

        LibTCOD::Flush();
    }
}
