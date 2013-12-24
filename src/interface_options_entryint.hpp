#pragma once
#include "interface_options_entry.hpp"

class OptionsEntryInt : public OptionsEntry
{
public:
    int* value;

    OptionsEntryInt(std::string label, int* value);

    virtual void Loop();
    virtual void Display();
    virtual bool IsPointInBoundaries(Vector2 pos);
    virtual bool IsPointInBoundaries(uint8_t x, uint8_t y);
};
