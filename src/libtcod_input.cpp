#include "libtcod_input.hpp"

namespace LibTCOD
{
    TCOD_key_t key;
    TCOD_mouse_t mouse;
    TCOD_event_t ev;

    void CheckForEvent()
    {
        ev = TCODSystem::checkForEvent(TCOD_EVENT_ANY,&key,&mouse);
    }
}
