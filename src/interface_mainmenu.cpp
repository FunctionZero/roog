#include "libtcod_input.hpp"
#include "interface_mainmenu.hpp"
#include "interface_game.hpp"
#include "interface_options.hpp"
#include "system_global.hpp"
#include "game_main.hpp"

namespace MainMenu
{
    std::vector<MainMenuEntry> vectorMenuEntry;
    int8_t currentMenuEntry;

    void PushBack(std::string label, int x, int y, bool isEnabled)
    {
        vectorMenuEntry.push_back(MainMenuEntry(label, x, y, isEnabled));
        vectorMenuEntry.back().ID = vectorMenuEntry.size() - 1;
    }

    void Initialize()
    {
        PushBack("New Game", 1, 1, true);
        PushBack("Load/Save", 1, 2, true);
        PushBack("Resume Game", 1, 3, true);
        PushBack("Options", 1, 5, true);
        PushBack("Exit Game", 1, 6, true);
    }

    void Open()
    {
        Global::ChangeGamestate(STATE_MAINMENU);
        currentMenuEntry = MM_UNINITIALIZED;

        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
            vectorMenuEntry[i].gradient = 0;

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

    void SelectMenuEntry(int8_t argInt)
    {
        currentMenuEntry = argInt;
    }

    void InterfaceUp()
    {
        if(currentMenuEntry > 0)
        {
            SelectMenuEntry(currentMenuEntry - 1);
            if(!vectorMenuEntry[currentMenuEntry].isEnabled)
                InterfaceUp();
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
                InterfaceDown();
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
        case MM_NEWGAME:
            Game::CreateDebugGame();
            Game::Open();
            break;

        case MM_LOADSAVE:
            break;

        case MM_RESUME:
            Game::Open();
            break;

        case MM_OPTIONS:
            Options::Open();
            break;

        case MM_EXIT:
            Global::endProgram = true;
            break;
        }
    }

    void CheckCursor()
    {
        SelectMenuEntry(MM_UNINITIALIZED);

        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
        {
            if(vectorMenuEntry[i].isEnabled && vectorMenuEntry[i].IsPointInBoundaries(LibTCOD::mouse.cx, LibTCOD::mouse.cy))
            {
                SelectMenuEntry(i);
                return;
            }

        }
    }
}
