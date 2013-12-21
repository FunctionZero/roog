#pragma once
#include "game_class.hpp"
#include "system_vector2.hpp"

namespace Game
{
    extern classGame* Game;

    void CreateDebugGame();
    bool IsPositionLegal(Vector2 vect);
    bool IsPositionLegal(int x, int y);

    void Tick();
}
