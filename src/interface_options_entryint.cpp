#include "interface_options_entryint.hpp"

OptionsEntryInt::OptionsEntryInt(std::string label, int* value) : OptionsEntry(label)
{
    this->value = value;
}

void OptionsEntryInt::Loop()
{

}

void OptionsEntryInt::Display()
{

}

bool OptionsEntryInt::IsPointInBoundaries(Vector2 pos)
{
    return IsPointInBoundaries(pos.x, pos.y);
}

bool OptionsEntryInt::IsPointInBoundaries(uint8_t x, uint8_t y)
{

}
