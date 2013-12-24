#pragma once
#include "interface_options_entry.hpp"

class OptionsEntryInt : public OptionsEntry
{
public:
    int* value;
    int min;
    int max;

    OptionsEntryInt(std::string label, int* value, int min, int max);

    void Loop();
    void Display(uint8_t x, uint8_t y);
    void Left();
    void Right();
    void ShiftLeft();
    void ShiftRight();
    void Enter();
    void CheckLength();
};
