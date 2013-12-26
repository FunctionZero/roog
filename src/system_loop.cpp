#include <string>
#include "system_loop.hpp"
#include "system_global.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_mainmenu.hpp"
#include "interface_game.hpp"
#include "interface_options.hpp"

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

        case STATE_GAME:
            Game::Loop();
            break;

        case STATE_OPTIONS:
            Options::Loop();
            break;
        }

        TCODConsole::root->print(0, 49, std::to_string(TCODSystem::getFps()).c_str());

        LibTCOD::Flush();
    }
}
