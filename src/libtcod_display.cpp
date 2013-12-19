#include "libtcod_display.hpp"
#include "libtcod.hpp"

namespace LibTCOD
{
    void Clear()
    {
        TCODConsole::root->clear();
    }

    void Flush()
    {
        TCODConsole::flush();
    }
}
