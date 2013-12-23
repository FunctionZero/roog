#include <vector>
#include "libtcod_display.hpp"
#include "libtcod_input.hpp"
#include "interface_mainmenu.hpp"
#include "interface_mainmenu_menuentry.hpp"

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
    if(IsSelected() && gradient < 100)
    {
        gradient += 65;
        if(gradient > 100)
            gradient = 100;
    }

    else if(!IsSelected() && gradient > 0)
    {
        if(gradient < 18)
            gradient = 0;
        else
            gradient -= 18;
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

    else
    {
        TCODConsole::root->setBackgroundFlag(TCOD_BKGND_SET);
        TCODConsole::root->setDefaultBackground(TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 100.0f));
        TCODConsole::root->print(pos.x, pos.y, extendedLabel.c_str());
        TCODConsole::root->setDefaultBackground(TCODColor::black);
    }
}

void MenuEntry::OnSelect()
{

}

bool MenuEntry::IsSelected()
{
    return (this - MainMenu::vectorMenuEntry.data() == MainMenu::currentMenuEntry);
}

bool MenuEntry::IsMouseInBoundaries(Vector2 pos)
{
    return IsMouseInBoundaries(pos.x, pos.y);
}

bool MenuEntry::IsMouseInBoundaries(uint8_t x, uint8_t y)
{
    return LibTCOD::mouse.cx >= (uint8_t)pos.x - 1 &&
           LibTCOD::mouse.cx <= (uint8_t)pos.x + (uint8_t)label.length() + 1 &&
           LibTCOD::mouse.cy == (uint8_t)pos.y;
}
