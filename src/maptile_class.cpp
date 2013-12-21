#include "maptile_class.hpp"
#include "system_random.hpp"

MapTile::MapTile(Map* ParentMap)
{
    this->ParentMap = ParentMap;
    this->SetParent(nullptr);

    if(RandomOneIn(6))
    {
        passable = false;
        transparent = false;
        DisplayChar = 'T';
        DisplayColor = &TCODColor::green;
    }

    else
    {
        passable = true;
        transparent = true;
        DisplayChar = '.';
        DisplayColor = &TCODColor::darkGrey;
    }
}

void MapTile::Copy(const MapTile& tile)
{
    passable = tile.passable;
    transparent = tile.transparent;
    DisplayChar = tile.DisplayChar;
    DisplayColor = tile.DisplayColor;
}
