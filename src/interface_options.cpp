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
    uint8_t topmostOptionsEntry;

    void PushBackBool(std::string label, bool* value)
    {
        vectorOptionsBool.push_back(OptionsEntryBool(label, value));
        vectorOptions.push_back(&vectorOptionsBool.back());
        vectorOptions.back()->ID = vectorOptions.size() - 1;
    }

    void PushBackInt(std::string label, int* value)
    {
        vectorOptionsInt.push_back(OptionsEntryInt(label, value));
        vectorOptions.push_back(&vectorOptionsInt.back());
        vectorOptions.back()->ID = vectorOptions.size() - 1;
    }

    void Initialize()
    {
        PushBackBool("Mouse Support", &IsMouseEnabled);
        PushBackInt("Sight Radius", &PlayerSightRadius);
    }

    void Open()
    {
        currentOptionsEntry = -1;
        topmostOptionsEntry = 0;
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

    void InterfaceEnter()
    {

    }

    void CheckCursor()
    {

    }
}
