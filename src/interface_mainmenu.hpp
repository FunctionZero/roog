#pragma once
#include <string>
#include <vector>
#include "system_vector2.hpp"
#include "boost_fixedwidth.hpp"
#include "interface_mainmenu_menuentry.hpp"

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
    extern std::vector<MenuEntry> vectorMenuEntry;
    extern int8_t currentMenuEntry;

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
