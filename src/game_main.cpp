#include "game_main.hpp"
#include "libtcod.hpp"

namespace Game
{
    classGame* Game;

    void CreateDebugGame()
    {
        Game = new classGame();
        Game->CurrentMap = new Map(100, 100);

        Game->PlayerObject = Game->CurrentMap->GetTileAt(1,1)->CreateChild();
        Game->PlayerObject->DisplayColor = &TCODColor::red;
        Game->PlayerObject->DisplayChar = '@';
    }

    bool IsPositionLegal(Vector2 vect)
    {
        return(Game->CurrentMap->IsPositionLegal(vect.x, vect.y));
    }

    bool IsPositionLegal(int x, int y)
    {
        return(Game->CurrentMap->IsPositionLegal(x, y));
    }

}
