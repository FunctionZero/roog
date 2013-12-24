#pragma once
#include <vector>
#include "interface_options.hpp"
#include "interface_options_entrybool.hpp"
#include "interface_options_entryint.hpp"

namespace Options
{
    extern std::vector<OptionsEntry*> vectorOptions;
    extern std::vector<OptionsEntryBool> vectorOptionsBool;
    extern std::vector<OptionsEntryInt> vectorOptionsInt;
    extern int8_t currentOptionsEntry;

    extern uint8_t viewportPosX;
    extern uint8_t viewportPosY;
    extern uint8_t viewportHeight;
    extern uint8_t viewportEntryOffset;

    void PushBackBool(std::string label, bool* value);
    void PushBackInt(std::string label, int* value, int min, int max);

    void Initialize();
    void Open();
    void Loop();
    void Input();
    void Display();
    void SelectOptionsEntry(int8_t argInt);
    void InterfaceUp();
    void InterfaceDown();
    void InterfaceLeft();
    void InterfaceRight();
    void InterfaceEnter();
    void CheckCursor();
}
