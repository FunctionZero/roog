#pragma once
#include <list>
#include "map_class.hpp"
#include "object_base.hpp"
#include "game_objectpool.hpp"
#include "game_templatepool.hpp"

class classGame
{
public:
    Map* CurrentMap;
    Object* PlayerObject;

    ObjectPool Objects;

    classGame();
    ~classGame();
};
