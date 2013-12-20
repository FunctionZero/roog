#pragma once
#include <string>
#include "system_vector2.hpp"

class MenuEntry
{
public:
    Vector2 pos;
    std::string label;
    bool isEnabled;

    uint8_t gradient;

    MenuEntry(std::string label, Vector2 pos, bool isEnabled);
    MenuEntry(std::string label, int x, int y, bool isEnabled);

    void Loop();
    void Display();
    void OnSelect();

    bool IsSelected();
};
