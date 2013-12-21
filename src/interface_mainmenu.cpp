#include "libtcod_input.hpp"
#include "interface_mainmenu.hpp"
#include "system_global.hpp"
#include "game_main.hpp"

namespace MainMenu
{
    std::vector<MenuEntry> vectorMenuEntry;
    int8_t currentMenuEntry;

    void Initialize()
    {
        vectorMenuEntry.push_back(MenuEntry("New Game", 1, 1, true));
        vectorMenuEntry.push_back(MenuEntry("Load/Save", 1, 2, true));
        vectorMenuEntry.push_back(MenuEntry("Resume Game", 1, 3, true));
        vectorMenuEntry.push_back(MenuEntry("Options", 1, 5, true));
        vectorMenuEntry.push_back(MenuEntry("Exit Game", 1, 6, true));
    }

    void Open()
    {
        Global::ChangeGamestate(STATE_MAINMENU);
        currentMenuEntry = MM_UNINITIALIZED;

        vectorMenuEntry[MM_LOADSAVE].isEnabled = (Game::Game != nullptr);
        vectorMenuEntry[MM_RESUME].isEnabled = (Game::Game != nullptr);
    }

    void Loop()
    {
        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
            vectorMenuEntry[i].Loop();

        Input();

        Display();
    }

    void Input()
    {
        if(LibTCOD::ev == TCOD_EVENT_KEY_PRESS)
        {
            switch(LibTCOD::key.vk)
            {
            case TCODK_ENTER:
                InterfaceEnter();
                break;

            case TCODK_UP:
                InterfaceUp();
                break;

            case TCODK_DOWN:
                InterfaceDown();
                break;

            default:
                break;
            }
        }

        if(LibTCOD::ev == TCOD_EVENT_MOUSE_MOVE || LibTCOD::mouse.lbutton_pressed)
        {
            CheckCursor();

            if(LibTCOD::mouse.lbutton_pressed)
            {
                InterfaceEnter();
            }
        }
    }

    void Display()
    {
        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
            vectorMenuEntry[i].Display();
    }

    void SelectMenuEntry(int8_t nMenuEntry)
    {
        currentMenuEntry = nMenuEntry;
        if(nMenuEntry != -1 || nMenuEntry < (uint8_t)vectorMenuEntry.size())
            vectorMenuEntry[nMenuEntry].OnSelect();
    }

    void InterfaceUp()
    {
        if(currentMenuEntry > 0)
        {
            SelectMenuEntry(currentMenuEntry - 1);

            if(!vectorMenuEntry[currentMenuEntry].isEnabled)
            {
                InterfaceUp();
            }
        }

        else
        {
            SelectMenuEntry(vectorMenuEntry.size() - 1);
        }
    }

    void InterfaceDown()
    {
        if(currentMenuEntry < (uint8_t)vectorMenuEntry.size() - 1)
        {
            SelectMenuEntry(currentMenuEntry + 1);
            if(!vectorMenuEntry[currentMenuEntry].isEnabled)
            {
                InterfaceDown();
            }
        }

        else
        {
            SelectMenuEntry(0);
        }
    }

    void InterfaceEnter()
    {
        switch(currentMenuEntry)
        {
        case MM_EXIT:
            Global::endProgram = true;
            break;

        default:
            break;
        }
    }

    void CheckCursor()
    {
        SelectMenuEntry(MM_UNINITIALIZED);

        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
        {
            if(vectorMenuEntry[i].isEnabled &&
               LibTCOD::mouse.cx >= (uint8_t)vectorMenuEntry[i].pos.x - 1 &&
               LibTCOD::mouse.cx <= (uint8_t)vectorMenuEntry[i].pos.x + (uint8_t)vectorMenuEntry[i].label.length() + 1 &&
               LibTCOD::mouse.cy == (uint8_t)vectorMenuEntry[i].pos.y)
               {
                   SelectMenuEntry(i);
               }
        }
    }
}
