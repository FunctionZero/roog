#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "interface_game.hpp"
#include "interface_mainmenu.hpp"
#include "system_global.hpp"
#include "game_main.hpp"

namespace Game
{
    uint8_t viewportPosX = 1;
    uint8_t viewportPosY = 1;
    uint8_t viewportSizeX = 35;
    uint8_t viewportSizeY = 35;

    void Initialize()
    {
        if(viewportSizeX % 2 == 0)
            viewportSizeX++;
        if(viewportSizeY % 2 == 0)
            viewportSizeY++;
    }

    void Open()
    {
        Global::ChangeGamestate(STATE_GAME);
    }

    void Loop()
    {
        Input();

        Display();
    }

    void Input()
    {
        if(LibTCOD::ev == TCOD_EVENT_KEY_PRESS)
        {
            switch(LibTCOD::key.vk)
            {
            case TCODK_ESCAPE:
                MainMenu::Open();
                break;

            default:
                break;
            }
        }
    }

    void Display()
    {
        TCODConsole::root->print(1, 0, "Press ESC to return to main menu.");
    }
}
