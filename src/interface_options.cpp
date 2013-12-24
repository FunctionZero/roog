#include <vector>
#include "interface_options.hpp"
#include "interface_options_entry.hpp"
#include "interface_options_entrybool.hpp"
#include "interface_options_entryint.hpp"
#include "interface_mainmenu.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "system_global.hpp"
#include "system_options.hpp"

namespace Options
{
    void Initialize()
    {
        std::vector<OptionsEntry> vectorOptions;
        vectorOptions.push_back(OptionsEntryBool("Mouse Support", &IsMouseEnabled));
        vectorOptions.push_back(OptionsEntryInt("Sight Radius", &PlayerSightRadius));
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
