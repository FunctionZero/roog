#include "game_main.hpp"
#include "libtcod.hpp"

namespace Game
{
    classGame* Game;

    void CreateDebugGame()
    {
        Game = new classGame();
        Game->CurrentMap = new Map(10, 10);

        Game->PlayerObject = Game->CurrentMap->GetTileAt(1,1)->CreateChild();
        Game->PlayerObject->DisplayColor = &TCODColor::red;
        Game->PlayerObject->DisplayChar = '@';
    }


}
