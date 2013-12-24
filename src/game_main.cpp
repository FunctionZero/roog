#include "game_main.hpp"
#include "misc_random.hpp"
#include "libtcod.hpp"

namespace Game
{
    classGame* Game;

    void CreateDebugGame()
    {
        Game = new classGame();
        Game->CurrentMap = new Map(100, 100);

        Game->PlayerObject = Game->Objects.NewObject(Game->CurrentMap->GetTileAt(Random(0, Game->CurrentMap->sizeX -1), Random(0, Game->CurrentMap->sizeY -1)), TemplatePool::Player);

        Tick();
    }

    bool IsPositionLegal(Vector2 vect)
    {
        return(Game->CurrentMap->IsPositionLegal(vect.x, vect.y));
    }

    bool IsPositionLegal(int x, int y)
    {
        return(Game->CurrentMap->IsPositionLegal(x, y));
    }

    void Tick()
    {
        Game->CurrentMap->CalculateFOV(Game->PlayerObject->GetPosition(), 16);
    }
}
