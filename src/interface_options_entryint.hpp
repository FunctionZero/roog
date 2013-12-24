#pragma once
#include "interface_options_entry.hpp"

class OptionsEntryInt : public OptionsEntry
{
public:
    int* value;
    int min;
    int max;

    OptionsEntryInt(std::string label, int* value, int min, int max);

    virtual void Loop();
    virtual void Display(uint8_t x, uint8_t y);
    virtual void Left();
    virtual void Right();
    virtual void ShiftLeft();
    virtual void ShiftRight();
    virtual void Enter();
    virtual bool IsPointInBoundaries(Vector2 pos);
    virtual bool IsPointInBoundaries(uint8_t x, uint8_t y);
};
