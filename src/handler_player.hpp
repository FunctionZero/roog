#pragma once
#include "entity_creature.hpp"

namespace Player
{
    extern Creature* Player;

    void Wait();

    void MoveN();
    void MoveNE();
    void MoveE();
    void MoveSE();
    void MoveS();
    void MoveSW();
    void MoveW();
    void MoveNW();
}
