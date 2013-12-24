#pragma once
#include <string>
#include <vector>
#include "system_vector2.hpp"
#include "boost_fixedwidth.hpp"
#include "interface_mainmenu_entry.hpp"

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
    extern std::vector<MainMenuEntry> vectorMenuEntry;
    extern int8_t currentMenuEntry;

    void PushBack(std::string label, int x, int y, bool isEnabled);
    void Initialize();
    void Open();
    void Loop();
    void Input();
    void Display();
    void SelectMenuEntry(int8_t argInt);
    void InterfaceUp();
    void InterfaceDown();
    void InterfaceEnter();
    void CheckCursor();
}
