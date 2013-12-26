#pragma once
#include <vector>
#include "libtcod.hpp"
#include "misc_vector2.hpp"
#include "boost_fixedwidth.hpp"

class Map
{
public:
    uint8_t sizeX;
    uint8_t sizeY;
    Map(uint8_t sizeX, uint8_t sizeY);

    TCODMap* MapFOV;
    void CalculateFOV(Vector2 vect, int radius = 0);
    void CalculateFOV(int x, int y, int radius = 0);


};
