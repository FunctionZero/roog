#include "libtcod_main.hpp"
#include "system_global.hpp"

namespace LibTCOD
{
    void Initialize()
    {
        TCODConsole::setCustomFont("data/font/terminal12x12_gs_ro.png",TCOD_FONT_LAYOUT_ASCII_INROW);
        TCODConsole::initRoot(Global::windowWidth, Global::windowHeight, "Roog");
        TCODSystem::setFps(25);
    }
}
