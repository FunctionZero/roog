#include <string>
#include "interface_options_entrybool.hpp"
#include "libtcod.hpp"

OptionsEntryBool::OptionsEntryBool(std::string label, bool* value) : OptionsEntry::OptionsEntry(label)
{
    this->value = value;
    if(*value)
        length = 4;
    else
        length = 5;
}

void OptionsEntryBool::Loop()
{
    OptionsEntry::Loop();
}

void OptionsEntryBool::Display(uint8_t x, uint8_t y)
{
    TCODColor tempColor = TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 100.0f);
    TCODColor tempColor2 = TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 200.0f);

    TCODConsole::root->setBackgroundFlag(TCOD_BKGND_SET);
    TCODConsole::root->setDefaultBackground(tempColor);

    if(*value)
        TCODConsole::root->print(x, y, "[TRUE] ");

    else
        TCODConsole::root->print(x, y, "[FALSE]");

    TCODConsole::root->setDefaultBackground(tempColor2);
    TCODConsole::root->setCharBackground(x+2+length, y, tempColor2);
    TCODConsole::root->print(x+3+length, y, label.c_str());
    TCODConsole::root->setDefaultBackground(TCODColor::black);
}

void OptionsEntryBool::Left()
{
    Enter();
}

void OptionsEntryBool::Right()
{
    Enter();
}

void OptionsEntryBool::ShiftLeft()
{
    Enter();
}

void OptionsEntryBool::ShiftRight()
{
    Enter();
}

void OptionsEntryBool::Enter()
{
    (*value) = !(*value);
    if(*value)
        length = 4;
    else
        length = 5;
}
