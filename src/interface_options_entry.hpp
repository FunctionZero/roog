#pragma once
#include "interface_entry.hpp"

class OptionsEntry : public BaseEntry
{
public:
    std::string label;
    uint8_t gradient;
    uint8_t length;

    OptionsEntry(std::string label);

    virtual void Loop();
    virtual void Display();
    virtual void Display(uint8_t x, uint8_t y) = 0;
    virtual void Left() = 0;
    virtual void Right() = 0;
    virtual void ShiftLeft() = 0;
    virtual void ShiftRight() = 0;
    virtual void Enter() = 0;
    virtual bool IsSelected();
};
