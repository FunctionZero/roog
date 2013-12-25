#pragma once
#include <list>
#include "game_mappool.hpp"
#include "game_objectpool.hpp"
#include "game_templatepool.hpp"

class Map;
class Object;

class classGame
{
public:
    Map* CurrentMap;
    Object* PlayerObject;

    MapPool Maps;
    ObjectPool Objects;

    classGame();
    ~classGame();
};
