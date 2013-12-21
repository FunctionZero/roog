#pragma once
#include <vector>
#include "system_vector2.hpp"
#include "boost_fixedwidth.hpp"
#include "maptile_class.hpp"

class Map
{
public:
    uint8_t sizeX;
    uint8_t sizeY;

    std::vector<MapTile> vectorMapTile;

    Map(uint8_t sizeX, uint8_t sizeY);

    MapTile* GetTileAt(Vector2 position);
    MapTile* GetTileAt(int x, int y);

    bool IsPositionLegal(Vector2 vect);
    bool IsPositionLegal(int x, int y);
};
