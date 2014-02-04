#include "game_map.hpp"

Map::Map(uint8_t sizeX, uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    VectorMaptile.reserve(sizeX*sizeY);

    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            VectorMaptile.emplace_back();
            VectorMaptile.back().posX = x;
            VectorMaptile.back().posY = y;
            VectorMaptile.back().ParentMap = this;
        }
    }

    MapFOV = new TCODMap(sizeX, sizeY);
}

void Map::ReinterpretFOV()
{
    for(int y = 0; y < sizeY; y++)
    {
        for(int x = 0; x < sizeX; x++)
        {
            ReinterpretFOV(x, y);
        }
    }
}

void Map::ReinterpretFOV(Vector2 vect)
{
    ReinterpretFOV(vect.x, vect.y);
}

void Map::ReinterpretFOV(uint16_t x, uint16_t y)
{
    Maptile* pointer = GetTileAt(x, y);
    MapFOV->setProperties(x, y, pointer->isTransparent, pointer->isPassable);
}

void Map::CalculateFOV(Vector2 vect, int radius)
{
    CalculateFOV(vect.x, vect.y, radius);
}

void Map::CalculateFOV(uint16_t x, uint16_t y, int radius)
{
    MapFOV->computeFov(x, y, radius, true, FOV_PERMISSIVE_8);
}

Maptile* Map::GetTileAt(Vector2 vect)
{
    return(&VectorMaptile[vect.y * sizeX + vect.x]);
}

Maptile* Map::GetTileAt(uint16_t x, uint16_t y)
{
    return(&VectorMaptile[y * sizeX + x]);
}

bool Map::IsInBounds(Vector2 vect)
{
    return(Map::IsInBounds(vect.x, vect.y));
}

bool Map::IsInBounds(uint16_t x, uint16_t y)
{
    return(x >= 0 && x < this->sizeY && y >= 0 && y < this->sizeY);
}

bool Map::IsPassable(Vector2 vect)
{
    return(Map::IsPassable(vect.x, vect.y));
}

bool Map::IsPassable(uint16_t x, uint16_t y)
{
    return(GetTileAt(x, y)->isPassable);
}

bool Map::IsTransparent(Vector2 vect)
{
    return(Map::IsTransparent(vect.x, vect.y));
}

bool Map::IsTransparent(uint16_t x, uint16_t y)
{
    return(GetTileAt(x, y)->isTransparent);
}

bool Map::IsOccupied(Vector2 vect)
{
    return(Map::IsOccupied(vect.x, vect.y));
}

bool Map::IsOccupied(uint16_t x, uint16_t y)
{
    Maptile* tile = GetTileAt(x, y);
    for(auto it: tile->Child)
    {
        if(it->Type == EntityType::Creature)
            return true;
    }

    return false;
}

