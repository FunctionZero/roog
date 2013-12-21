#pragma once

enum enumGameState
{
    STATE_MAINMENU,
    STATE_GAME
};

namespace Global
{
    extern int windowWidth;
    extern int windowHeight;
    extern bool endProgram;

    extern enumGameState gameState;

    void ChangeGamestate(enumGameState gs);
}
