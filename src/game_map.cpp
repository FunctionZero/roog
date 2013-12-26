#include "game_map.hpp"

Map::Map(uint8_t sizeX, uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    MapFOV = new TCODMap(sizeX, sizeY);
}

void Map::CalculateFOV(Vector2 vect, int radius)
{
    CalculateFOV(vect.x, vect.y, radius);
}

void Map::CalculateFOV(int x, int y, int radius)
{
    MapFOV->computeFov(x, y, radius, true, FOV_PERMISSIVE_8);
}
