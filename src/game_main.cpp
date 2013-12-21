#include "game_main.hpp"

namespace Game
{
    classGame* Game;

    void CreateDebugGame()
    {
        Game = new classGame();
        Game->CurrentMap = new Map(10, 10);
    }
}
