#include <vector>
#include "interface_options.hpp"
#include "interface_mainmenu.hpp"
#include "libtcod_input.hpp"
#include "libtcod_display.hpp"
#include "system_global.hpp"
#include "system_options.hpp"

namespace Options
{
    std::vector<OptionsEntry*> vectorOptions;
    std::vector<OptionsEntryBool> vectorOptionsBool;
    std::vector<OptionsEntryInt> vectorOptionsInt;
    int8_t currentOptionsEntry;

    uint8_t viewportPosX = 1;
    uint8_t viewportPosY = 2;
    uint8_t viewportHeight = 10;
    uint8_t viewportEntryOffset = 0;

    void PushBackBool(std::string label, bool* value)
    {
        vectorOptionsBool.emplace_back(label, value);
        vectorOptions.push_back(&vectorOptionsBool.back());
        vectorOptions.back()->ID = vectorOptions.size() - 1;
    }

    void PushBackInt(std::string label, int* value, int min, int max)
    {
        vectorOptionsInt.emplace_back(label, value, min, max);
        vectorOptions.push_back(&vectorOptionsInt.back());
        vectorOptions.back()->ID = vectorOptions.size() - 1;
    }

    void Initialize()
    {
        PushBackBool("Mouse Support", &IsMouseEnabled);
        PushBackInt("Sight Radius", &PlayerSightRadius, -1, 10);
    }

    void Open()
    {
        currentOptionsEntry = -1;
        viewportEntryOffset = 0;
        Global::ChangeGamestate(STATE_OPTIONS);
    }

    void Loop()
    {
        for(unsigned int i = 0; i < vectorOptions.size(); i++)
            vectorOptions[i]->Loop();

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

            case TCODK_ENTER:
                InterfaceEnter();
                break;

            case TCODK_UP:
                InterfaceUp();
                break;

            case TCODK_DOWN:
                InterfaceDown();
                break;

            case TCODK_LEFT:
                InterfaceLeft();
                break;

            case TCODK_RIGHT:
                InterfaceRight();
                break;

            default:
                break;
            }
        }

        CheckCursor();

        if(LibTCOD::mouse.lbutton_pressed)
            {
                InterfaceEnter();
            }
    }

    void Display()
    {
        for(unsigned int i = 0; i < vectorOptions.size(); i++)
            vectorOptions[i]->Display(1, 2+i);

        TCODConsole::root->print(1, 0, "Press ESC to return to main menu.");
    }

    void SelectOptionsEntry(int8_t argInt)
    {
        currentOptionsEntry = argInt;
    }

    void InterfaceUp()
    {
        if(currentOptionsEntry > 0)
            SelectOptionsEntry(currentOptionsEntry - 1);

        else
            SelectOptionsEntry(vectorOptions.size() - 1);
    }

    void InterfaceDown()
    {
        if(currentOptionsEntry < (uint8_t)vectorOptions.size() - 1)
            SelectOptionsEntry(currentOptionsEntry + 1);

        else
            SelectOptionsEntry(0);
    }

    void InterfaceLeft()
    {
        if(currentOptionsEntry >= 0 && currentOptionsEntry < (int)vectorOptions.size())
        {
            if(LibTCOD::key.shift)
                vectorOptions[currentOptionsEntry]->ShiftLeft();
            else
                vectorOptions[currentOptionsEntry]->Left();
        }
    }

    void InterfaceRight()
    {
        if(currentOptionsEntry >= 0 && currentOptionsEntry < (int)vectorOptions.size())
        {
            if(LibTCOD::key.shift)
                vectorOptions[currentOptionsEntry]->ShiftRight();
            else
                vectorOptions[currentOptionsEntry]->Right();
        }
    }

    void InterfaceEnter()
    {
        if(currentOptionsEntry >= 0 && currentOptionsEntry < (int)vectorOptions.size())
        {
            vectorOptions[currentOptionsEntry]->Enter();
        }
    }

    void CheckCursor()
    {
        if(LibTCOD::ev == TCOD_EVENT_MOUSE_MOVE || LibTCOD::mouse.lbutton_pressed)
        {
            SelectOptionsEntry(-1);

            for(unsigned int i = viewportEntryOffset; i < vectorOptions.size(); i++)
                if((uint8_t)LibTCOD::mouse.cx >= viewportPosX &&
                   (uint8_t)LibTCOD::mouse.cx <= viewportPosX + vectorOptions[i]->length &&
                   (uint8_t)LibTCOD::mouse.cy == viewportPosY + i)
                {
                   SelectOptionsEntry(i);
                   return;
                }
        }
    }
}
