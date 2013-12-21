#include "libtcod_input.hpp"
#include "interface_game.hpp"
#include "interface_mainmenu.hpp"
#include "system_global.hpp"

namespace Game
{
    void Initialize()
    {

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

    }
}
