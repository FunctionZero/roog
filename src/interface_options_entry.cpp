#include "interface_options_entry.hpp"

OptionsEntry::OptionsEntry(std::string label) : BaseEntry(label)
{
    gradient = 0;
}


void OptionsEntry::Loop()
{

}

void OptionsEntry::Display()
{

}

bool OptionsEntry::IsSelected()
{

}

bool OptionsEntry::IsPointInBoundaries(Vector2 pos)
{
    return false;
}

bool OptionsEntry::IsPointInBoundaries(uint8_t x, uint8_t y)
{
    return false;
}
