#include "game_main.hpp"
#include "template_factory.hpp"
#include "worldgen_main.hpp"
#include "entity_creature.hpp"
#include "entity_factory.hpp"
#include "misc_random.hpp"
#include "handler_player.hpp"
#include "libtcod.hpp"

namespace Game
{
    classGame* Game;

    void NewGame()
    {
        if(Game != nullptr)
            delete Game;
        Game = new classGame;

        Game->currentMap = new Map(100, 100);
        TemplateFactory::MakeDebugTMaptileList(&Game->TMaptileMap);
        TemplateFactory::MakeDebugTCreatureList(&Game->TCreatureMap);
        Worldgen::GenerateDebugForest(Game->currentMap, &Game->TMaptileMap);
        Game->currentMap->ReinterpretFOV();

        Player::Player = EntityFactory::CreateCreature(CreatureType::Player);
        Player::Player->SetParent(Game->currentMap->GetTileAt(Random(0,99), Random(0,99)));
        Game->currentMap->CalculateFOV(Player::Player->GetPosition());

    }
}
