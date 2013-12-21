#include "map_class.hpp"

Map::Map(uint8_t sizeX, uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    MapFOV = new TCODMap(sizeX, sizeY);

    for(unsigned int y = 0; y < sizeY; y++)
    {
        for(unsigned int x = 0; x < sizeX; x++)
        {
            vectorMapTile.emplace_back(this);
            vectorMapTile.back().posX = x;
            vectorMapTile.back().posY = y;

            MapFOV->setProperties(x, y, vectorMapTile.back().transparent, vectorMapTile.back().passable);
        }
    }
}

void Map::CalculateFOV(Vector2 vect, int radius)
{
    CalculateFOV(vect.x, vect.y, radius);
}

void Map::CalculateFOV(int x, int y, int radius)
{
    MapFOV->computeFov(x, y, radius, true, FOV_PERMISSIVE_8);
}

MapTile* Map::GetTileAt(Vector2 vect)
{
    return(&vectorMapTile[vect.y * sizeX + vect.x]);
}

MapTile* Map::GetTileAt(int x, int y)
{
    return(&vectorMapTile[y * sizeX + x]);
}

bool Map::IsPositionLegal(Vector2 vect)
{
    return(Map::IsPositionLegal(vect.x, vect.y));
}

bool Map::IsPositionLegal(int x, int y)
{
    return(x >= 0 && x < this->sizeY && y >= 0 && y < this->sizeY);
}
