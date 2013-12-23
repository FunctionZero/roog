#pragma once
#include "interface_entry.hpp"

class OptionsEntry : public BaseEntry
{
    std::string label;
    uint8_t gradient;

    OptionsEntry(std::string label);

    void Loop();
    void Display();
    bool IsSelected();
    bool IsMouseInBoundaries(Vector2 pos);
    bool IsMouseInBoundaries(uint8_t x, uint8_t y);
};
