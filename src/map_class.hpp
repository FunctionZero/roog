#pragma once
#include <vector>
#include "libtcod.hpp"
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

    TCODMap* MapFOV;
    void CalculateFOV(Vector2 vect, int radius = 0);
    void CalculateFOV(int x, int y, int radius = 0);

    MapTile* GetTileAt(Vector2 vect);
    MapTile* GetTileAt(int x, int y);

    bool IsPositionLegal(Vector2 vect);
    bool IsPositionLegal(int x, int y);


};
