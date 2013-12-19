#pragma once
#include "libtcod.hpp"

namespace LibTCOD
{
    extern TCOD_key_t key;
    extern TCOD_mouse_t mouse;
    extern TCOD_event_t ev;

    void CheckForEvent();
}
