#include "libtcod_input.hpp"
#include "interface_game.hpp"
#include "system_global.hpp"

namespace Game
{
    void Initialize()
    {

    }

    void Open()
    {
        Global::ChangeGamestate(STATE_GAME);
    }

    void Loop()
    {
        Input();

        Display();
    }

    void Input()
    {

    }

    void Display()
    {

    }
}
