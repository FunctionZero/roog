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
    virtual void Display(uint8_t x, uint8_t y);
    virtual bool IsSelected();
    virtual bool IsPointInBoundaries(Vector2 pos);
    virtual bool IsPointInBoundaries(uint8_t x, uint8_t y);
};
