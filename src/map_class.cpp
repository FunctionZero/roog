#include "map_class.hpp"

Map::Map(uint8_t sizeX, uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    for(unsigned int y = 0; y < sizeY; y++)
    {
        for(unsigned int x = 0; x < sizeX; x++)
        {
            vectorMapTile.emplace_back(this);
            vectorMapTile.back().posX = x;
            vectorMapTile.back().posY = y;
        }
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

bool Map::IsPositionLegal(Vector2 vect)
{
    return(Map::IsPositionLegal(vect.x, vect.y));
}

bool Map::IsPositionLegal(int x, int y)
{
    return(x >= 0 && x < this->sizeY && y >= 0 && y < this->sizeY);
}
