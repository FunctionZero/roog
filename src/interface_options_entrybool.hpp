#pragma once
#include "interface_options_entry.hpp"

class OptionsEntryBool : public OptionsEntry
{
public:
    bool* value;

    OptionsEntryBool(std::string label, bool* value);

    virtual void Loop();
    virtual void Display(uint8_t x, uint8_t y);
    virtual bool IsPointInBoundaries(Vector2 pos);
    virtual bool IsPointInBoundaries(uint8_t x, uint8_t y);
};
