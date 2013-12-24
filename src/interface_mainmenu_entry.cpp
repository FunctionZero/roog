#include <vector>
#include "libtcod_display.hpp"
#include "libtcod_input.hpp"
#include "interface_mainmenu_entry.hpp"
#include "interface_mainmenu.hpp"

MainMenuEntry::MainMenuEntry(std::string label, int x, int y, bool isEnabled) : BaseEntry(label)
{
    this->x = x;
    this->y = y;
    this->isEnabled = isEnabled;

    this->gradient = 0;
}

void MainMenuEntry::Loop()
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

void MainMenuEntry::Display()
{
    std::string extendedLabel;
    extendedLabel.append(" ").append(label).append(" ");

    if(!this->isEnabled)
    {
        TCODConsole::root->setDefaultForeground(TCODColor::darkGrey);
        TCODConsole::root->print(x, y, extendedLabel.c_str());
        TCODConsole::root->setDefaultForeground(TCODColor::white);
    }

    else
    {
        TCODConsole::root->setBackgroundFlag(TCOD_BKGND_SET);
        TCODConsole::root->setDefaultBackground(TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 100.0f));
        TCODConsole::root->print(x, y, extendedLabel.c_str());
        TCODConsole::root->setDefaultBackground(TCODColor::black);
    }
}

bool MainMenuEntry::IsSelected()
{
    return ID == MainMenu::currentMenuEntry;
}

bool MainMenuEntry::IsPointInBoundaries(Vector2 pos)
{
    return IsPointInBoundaries(pos.x, pos.y);
}

bool MainMenuEntry::IsPointInBoundaries(uint8_t x, uint8_t y)
{
    return x >= this->x - 1 &&
           x <= this->x + this->label.length() + 1 &&
           y == this->y;
}
