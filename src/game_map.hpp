#pragma once
#include <vector>
#include "libtcod.hpp"
#include "misc_vector2.hpp"
#include "boost_fixedwidth.hpp"
#include "entity_maptile.hpp"

class Map
{
public:
    uint8_t sizeX;
    uint8_t sizeY;
    std::vector<Maptile> VectorMaptile;

    Map(uint8_t sizeX, uint8_t sizeY);

    TCODMap* MapFOV;
    void ReinterpretFOV();
    void ReinterpretFOV(Vector2 vect);
    void ReinterpretFOV(uint16_t x, uint16_t y);
    void CalculateFOV(Vector2 vect, int radius = 0);
    void CalculateFOV(uint16_t x, uint16_t y, int radius = 0);

    Maptile* GetTileAt(Vector2 vect);
    Maptile* GetTileAt(uint16_t x, uint16_t y);
    bool IsInBounds(Vector2 vect);
    bool IsInBounds(uint16_t x, uint16_t y);
    bool IsPassable(Vector2 vect);
    bool IsPassable(uint16_t x, uint16_t y);
    bool IsTransparent(Vector2 vect);
    bool IsTransparent(uint16_t x, uint16_t y);
    bool IsOccupied(Vector2 vect);
    bool IsOccupied(uint16_t x, uint16_t y);
};
