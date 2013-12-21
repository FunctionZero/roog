#include "map_class.hpp"

Map::Map(uint8_t sizeX, uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    for(unsigned int i = 0; i < sizeX*sizeY; i++)
    {
        vectorMapTile.push_back(MapTile(this));
    }
}

MapTile* Map::GetTileAt(Vector2 position)
{
    return(&vectorMapTile[position.y * sizeX + position.x]);
}

MapTile* Map::GetTileAt(int x, int y)
{
    return(&vectorMapTile[y * sizeX + x]);
}
