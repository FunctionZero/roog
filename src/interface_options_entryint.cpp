#include <string>
#include <sstream>
#include "interface_options_entryint.hpp"
#include "libtcod.hpp"

OptionsEntryInt::OptionsEntryInt(std::string label, int* value, int min, int max) : OptionsEntry(label)
{
    this->value = value;
    this->min = min;
    this->max = max;

    CheckLength();
}

void OptionsEntryInt::Loop()
{
    OptionsEntry::Loop();
}

void OptionsEntryInt::Display(uint8_t x, uint8_t y)
{
    std::stringstream tempStream;
    std::string tempString;

    tempStream << (*value);
    std::getline(tempStream, tempString);

    TCODColor tempColor = TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 100.0f);
    TCODColor tempColor2 = TCODColor::lerp(TCODColor::black, TCODColor::darkRed, gradient / 200.0f);

    TCODConsole::root->setBackgroundFlag(TCOD_BKGND_SET);
    TCODConsole::root->setDefaultBackground(tempColor);
    TCODConsole::root->putCharEx(x, y, '[', TCODColor::white, tempColor);
    TCODConsole::root->print(x+1, y, tempString.c_str());
    TCODConsole::root->putCharEx(x+length, y, ']', TCODColor::white, tempColor);
    TCODConsole::root->setDefaultBackground(tempColor2);
    TCODConsole::root->setCharBackground(x+1+length, y, tempColor2);
    TCODConsole::root->print(x+2+length, y, label.c_str());
    TCODConsole::root->setDefaultBackground(TCODColor::black);
}

void OptionsEntryInt::Left()
{
    if((*value) <= min)
    {
        (*value) = min;
        gradient = 0;
    }
    else
        (*value)--;

    CheckLength();
}

void OptionsEntryInt::Right()
{
    if((*value) >= max)
    {
        (*value) = max;
        gradient = 0;
    }
    else
        (*value)++;

    CheckLength();
}

void OptionsEntryInt::ShiftLeft()
{
    for(int i = 0; i < 5; i++)
        Left();
}

void OptionsEntryInt::ShiftRight()
{
    for(int i = 0; i < 5; i++)
        Right();
}

void OptionsEntryInt::Enter()
{

}

void OptionsEntryInt::CheckLength()
{
    int tempInt = *value;

    if(tempInt <= 0)
        length = 2;
    else
        length = 1;

    while(tempInt)
    {
        tempInt /= 10;
        length++;
    }
}
