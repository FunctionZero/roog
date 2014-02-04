#pragma once
#include <list>
#include <map>
#include "game_map.hpp"
#include "entity_class.hpp"
#include "template_maptile.hpp"
#include "template_creature.hpp"

class classGame
{
public:
    Map* currentMap;
    std::list<Entity*> EntityList;
    std::map<MaptileType, TMaptile> TMaptileMap;
    std::map<CreatureType, TCreature> TCreatureMap;

    classGame();
    ~classGame();
};
