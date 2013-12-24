#include "object_maptile.hpp"
#include "misc_random.hpp"

MapTile::MapTile(Map* ParentMap)
{
    ParentMap = ParentMap;
    ObjectType = OBJECT_MAPTILE;

    if(RandomOneIn(8))
    {
        passable = false;
        transparent = false;
        DisplayChar = 'T';
        DisplayColor = &TCODColor::green;
    }

    else if(RandomOneIn(12))
    {
        passable = false;
        transparent = true;
        DisplayChar = 'o';
        DisplayColor = &TCODColor::grey;
    }

    else
    {
        passable = true;
        transparent = true;
        DisplayChar = '.';
        DisplayColor = &TCODColor::darkSepia;
    }
}

void MapTile::Copy(const MapTile& tile)
{
    passable = tile.passable;
    transparent = tile.transparent;
    DisplayChar = tile.DisplayChar;
    DisplayColor = tile.DisplayColor;
}

Vector2 MapTile::GetPosition()
{
    return Vector2(posX, posY);
}
