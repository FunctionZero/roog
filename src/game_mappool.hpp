#pragma once
#include <list>
#include "game_map.hpp"

class MapPool
{
public:
    std::list<Map> MapList;

    Map* NewMap(uint8_t sizeX, uint8_t sizeY);
};
