#include "system_global.hpp"

namespace Global
{
    int windowWidth = 80;
    int windowHeight = 50;
    bool endProgram = 0;

    enumGameState gameState;

    void ChangeGamestate(enumGameState gs)
    {
        gameState = gs;
    }
}
