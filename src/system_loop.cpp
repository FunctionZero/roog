#include "system_loop.hpp"
#include "system_global.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"

namespace System
{
    void Loop()
    {
        LibTCOD::Clear();
        LibTCOD::CheckForEvent();

        switch(Global::gameState)
        {
        /*
        case STATE_MAINMENU:
            MainMenu::Loop();
            break;

        case STATE_LOADSAVE:
            LoadSave::Loop();
            break;

        case STATE_OPTIONS:
            Options::Loop();
            break;

        case STATE_GAMEMAIN:
            Game::Loop();
            break;
        */
        }

        LibTCOD::Flush();
    }
}
