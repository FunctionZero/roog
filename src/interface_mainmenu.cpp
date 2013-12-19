#include "libtcod_display.hpp"
#include "libtcod_input.hpp"
#include "interface_mainmenu.hpp"
#include "system_global.hpp"


namespace MainMenu
{
    std::vector<MenuEntry> vectorMenuEntry;
    int8_t currentMenuEntry;

    void Initialize()
    {
        vectorMenuEntry.push_back(MenuEntry("New Game", 1, 1, true));
        vectorMenuEntry.push_back(MenuEntry("Load/Save", 1, 2, false));
        vectorMenuEntry.push_back(MenuEntry("Resume Game", 1, 3, false));
        vectorMenuEntry.push_back(MenuEntry("Options", 1, 5, true));
        vectorMenuEntry.push_back(MenuEntry("Exit Game", 1, 6, true));
    }

    void Open()
    {
        Global::gameState = STATE_MAINMENU;
        currentMenuEntry = MM_UNINITIALIZED;
    }

    void Loop()
    {
        Input();

        for(uint8_t i = 0; i < vectorMenuEntry.size(); i++)
            vectorMenuEntry[i].Loop();

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

        if(LibTCOD::ev == TCOD_EVENT_MOUSE_MOVE || LibTCOD::ev == TCOD_EVENT_MOUSE_PRESS)
        {
            CheckCursor();

            if(LibTCOD::ev == TCOD_EVENT_MOUSE_PRESS)
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

    void SelectMenuEntry(uint8_t nMenuEntry)
    {
        currentMenuEntry = nMenuEntry;
        if(nMenuEntry != -1 || nMenuEntry < vectorMenuEntry.size())
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

MenuEntry::MenuEntry(std::string label, Vector2 pos, bool isEnabled)
{
    this->pos = pos;
    this->label = label;
    this->isEnabled = isEnabled;
    this->gradient = 0;
}

MenuEntry::MenuEntry(std::string label, int x, int y, bool isEnabled)
{
    this->pos.x = x;
    this->pos.y = y;
    this->label = label;
    this->isEnabled = isEnabled;
    this->gradient = 0;
}

void MenuEntry::Loop()
{
    if((this - MainMenu::vectorMenuEntry.data() == MainMenu::currentMenuEntry) && gradient > 0)
    {
        if(gradient < 10)
            gradient = 0;
        else
            gradient -= 10;
    }
}

void MenuEntry::Display()
{
    std::string extendedLabel;
    extendedLabel.append(" ").append(label).append(" ");

    if(!this->isEnabled)
    {
        TCODConsole::root->setDefaultForeground(TCODColor::darkGrey);
        TCODConsole::root->print(pos.x, pos.y, extendedLabel.c_str());
        TCODConsole::root->setDefaultForeground(TCODColor::white);
    }

    else if(this - MainMenu::vectorMenuEntry.data() == MainMenu::currentMenuEntry)
    {
        TCODConsole::root->setBackgroundFlag(TCOD_BKGND_SET);
        TCODConsole::root->setDefaultBackground(TCODColor::darkRed);
        TCODConsole::root->print(pos.x, pos.y, extendedLabel.c_str());
        TCODConsole::root->setDefaultBackground(TCODColor::black);
    }

    else
    {
        TCODConsole::root->print(pos.x, pos.y, extendedLabel.c_str());
    }
}

void MenuEntry::OnSelect()
{
    this->gradient = 100;
}
