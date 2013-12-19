#pragma once

enum enumGameState
    {
        STATE_MAINMENU
    };

namespace Global
{
    extern int windowWidth;
    extern int windowHeight;
    extern bool endProgram;

    extern enumGameState gameState;
}
