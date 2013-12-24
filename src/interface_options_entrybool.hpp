#pragma once
#include "interface_options_entry.hpp"

class OptionsEntryBool : public OptionsEntry
{
public:
    bool* value;

    OptionsEntryBool(std::string label, bool* value);

    void Loop();
    void Display(uint8_t x, uint8_t y);
    void Left();
    void Right();
    void ShiftLeft();
    void ShiftRight();
    void Enter();
    void CheckLength();
};
