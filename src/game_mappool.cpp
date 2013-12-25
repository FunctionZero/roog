#include "game_mappool.hpp"

Map* MapPool::NewMap(uint8_t sizeX, uint8_t sizeY)
{
    MapList.emplace_back(sizeX, sizeY);
    return &MapList.back();
}
