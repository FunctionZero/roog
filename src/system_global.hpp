#pragma once

enum enumGameState
{
    STATE_MAINMENU,
    STATE_GAME,
    STATE_OPTIONS
};

namespace Global
{
    extern int windowWidth;
    extern int windowHeight;
    extern bool endProgram;

    extern enumGameState gameState;

    void ChangeGamestate(enumGameState gs);
}
