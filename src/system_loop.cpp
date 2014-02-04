#include <string>
#include <vector>
#include "system_loop.hpp"
#include "system_global.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_mainmenu.hpp"
#include "interface_game.hpp"
#include "interface_options.hpp"
#include "boost_fixedwidth.hpp"

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

        std::vector<uint64_t*> temp;

        for(int i = 0; i < 100000; i++)
        {
            temp.push_back(new uint64_t);
        }

        for(int i = 0; i < 100000; i++)
        {
            delete temp[i];
        }

        TCODConsole::root->print(0, 49, std::to_string(TCODSystem::getFps()).c_str());

        LibTCOD::Flush();
    }
}
