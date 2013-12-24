#include "interface_options_entry.hpp"
#include "interface_options.hpp"
#include "libtcod.hpp"

OptionsEntry::OptionsEntry(std::string label) : BaseEntry(label)
{
    this->label = label;
    gradient = 0;
}


void OptionsEntry::Loop()
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

void OptionsEntry::Display()
{

}

void OptionsEntry::Display(uint8_t x, uint8_t y)
{

}

bool OptionsEntry::IsSelected()
{
    return ID == Options::currentOptionsEntry;
}

bool OptionsEntry::IsPointInBoundaries(Vector2 pos)
{
    return false;
}

bool OptionsEntry::IsPointInBoundaries(uint8_t x, uint8_t y)
{
    return false;
}
