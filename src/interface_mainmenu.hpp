#pragma once
#include <string>
#include <vector>
#include "system_vector2.hpp"
#include "boost_fixedwidth.hpp"

enum enumMenuEntry
{
    MM_UNINITIALIZED = -1,
    MM_NEWGAME,
    MM_LOADSAVE,
    MM_RESUME,
    MM_OPTIONS,
    MM_EXIT
};

namespace MainMenu
{
    void Initialize();
    void Open();
    void Loop();

    void Input();
    void Display();

    void SelectMenuEntry(uint8_t nMenuEntry);

    void InterfaceUp();
    void InterfaceDown();
    void InterfaceEnter();
    void CheckCursor();
}

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
};
