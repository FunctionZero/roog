#include "interface_options_entrybool.hpp"

OptionsEntryBool::OptionsEntryBool(std::string label, bool* value) : OptionsEntry(label)
{
    this->value = value;
}

void OptionsEntryBool::Loop()
{

}

void OptionsEntryBool::Display()
{

}

bool OptionsEntryBool::IsPointInBoundaries(Vector2 pos)
{
    return IsPointInBoundaries(pos.x, pos.y);
}

bool OptionsEntryBool::IsPointInBoundaries(uint8_t x, uint8_t y)
{

}
