#include "entity_factory.hpp"
#include "entity_maptile.hpp"
#include "game_main.hpp"
#include "system_exception.hpp"

namespace EntityFactory
{
    Creature* CreateCreature()
    {
        Creature* pointer = new Creature();
        Game::Game->EntityList.push_back(pointer);
        return pointer;
    }

    Creature* CreateCreature(CreatureType arg)
    {
        Creature* pointer = CreateCreature();
        pointer->UseTemplate(&Game::Game->TCreatureMap.find(arg)->second);
        return pointer;
    }
}
