#include "interface_options.hpp"
#include "interface_mainmenu.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "system_global.hpp"

namespace Options
{
    void Initialize()
    {

    }

    void Open()
    {
        Global::ChangeGamestate(STATE_OPTIONS);
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
