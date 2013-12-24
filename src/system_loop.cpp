#include <sstream>
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

        char chararray[3];
        std::stringstream sstream;
        sstream << TCODSystem::getFps();
        sstream.getline(chararray, 3);

        TCODConsole::root->print(0, 49, chararray);

        LibTCOD::Flush();
    }
}
