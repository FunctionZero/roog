#pragma once
#include "interface_entry.hpp"

class MainMenuEntry : public BaseEntry
{
public:
    uint8_t x;
    uint8_t y;
    uint8_t gradient;
    bool isEnabled;

    MainMenuEntry(std::string label, Vector2 pos, bool isEnabled);
    MainMenuEntry(std::string label, int x, int y, bool isEnabled);

    void Loop();
    void Display();
    bool IsSelected();
    bool IsPointInBoundaries(Vector2 pos);
    bool IsPointInBoundaries(uint8_t x, uint8_t y);
};
